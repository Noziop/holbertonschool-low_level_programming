#!/bin/bash

# Color codes
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

# Function to validate integer input
is_valid_int() {
    [[ "$1" =~ ^[0-9]+$ ]]
}

# Function to validate float input
is_valid_float() {
    [[ "$1" =~ ^[0-9]+([.][0-9]+)?$ ]]
}

# Function to print colored output
print_colored() {
    local color=$1
    local message=$2
    echo -e "${color}${message}${NC}"
}

# Function to run custom examples
run_custom_example() {
    print_colored $BLUE "Configuration de sum_them_all :"
    read -p "Entrez le nombre d'arguments pour sum_them_all : " sum_count
    while ! is_valid_int "$sum_count" || [ "$sum_count" -eq 0 ]; do
        print_colored $RED "Veuillez entrer un nombre entier positif."
        read -p "Entrez le nombre d'arguments pour sum_them_all : " sum_count
    done
    sum_args=""
    for ((i=1; i<=sum_count; i++)); do
        read -p "Argument $i (entier) : " arg
        while ! is_valid_int "$arg"; do
            print_colored $RED "Veuillez entrer un nombre entier valide."
            read -p "Argument $i (entier) : " arg
        done
        sum_args+="$arg"
        [ $i -lt $sum_count ] && sum_args+=", "
    done

    print_colored $BLUE "Configuration de print_numbers :"
    read -p "Entrez le séparateur pour print_numbers : " num_separator
    read -p "Entrez le nombre d'arguments pour print_numbers : " num_count
    while ! is_valid_int "$num_count" || [ "$num_count" -eq 0 ]; do
        print_colored $RED "Veuillez entrer un nombre entier positif."
        read -p "Entrez le nombre d'arguments pour print_numbers : " num_count
    done
    num_args=""
    for ((i=1; i<=num_count; i++)); do
        read -p "Argument $i (entier) : " arg
        while ! is_valid_int "$arg"; do
            print_colored $RED "Veuillez entrer un nombre entier valide."
            read -p "Argument $i (entier) : " arg
        done
        num_args+="$arg"
        [ $i -lt $num_count ] && num_args+=", "
    done

    print_colored $BLUE "Configuration de print_strings :"
    read -p "Entrez le séparateur pour print_strings : " str_separator
    read -p "Entrez le nombre de chaînes pour print_strings : " str_count
    while ! is_valid_int "$str_count" || [ "$str_count" -eq 0 ]; do
        print_colored $RED "Veuillez entrer un nombre entier positif."
        read -p "Entrez le nombre de chaînes pour print_strings : " str_count
    done
    str_args=""
    for ((i=1; i<=str_count; i++)); do
        read -p "Chaîne $i : " arg
        str_args+="\"$arg\""
        [ $i -lt $str_count ] && str_args+=", "
    done

    print_colored $BLUE "Configuration de print_all :"
    read -p "Entrez le format pour print_all (c: char, i: int, f: float, s: string) : " all_format
    all_count=${#all_format}
    all_args=""
    for ((i=0; i<all_count; i++)); do
        case ${all_format:$i:1} in
            c)
                read -p "Entrez un caractère : " arg
                while [ ${#arg} -ne 1 ]; do
                    print_colored $RED "Veuillez entrer un seul caractère."
                    read -p "Entrez un caractère : " arg
                done
                all_args+=", '$arg'"
                ;;
            i)
                read -p "Entrez un entier : " arg
                while ! is_valid_int "$arg"; do
                    print_colored $RED "Veuillez entrer un nombre entier valide."
                    read -p "Entrez un entier : " arg
                done
                all_args+=", $arg"
                ;;
            f)
                read -p "Entrez un nombre à virgule flottante : " arg
                while ! is_valid_float "$arg"; do
                    print_colored $RED "Veuillez entrer un nombre à virgule flottante valide."
                    read -p "Entrez un nombre à virgule flottante : " arg
                done
                all_args+=", $arg"
                ;;
            s)
                read -p "Entrez une chaîne de caractères : " arg
                all_args+=", \"$arg\""
                ;;
            *)
                print_colored $RED "Format non reconnu : ${all_format:$i:1}. Ignoré."
                ;;
        esac
    done

    # Create temporary main file
    cat << EOF > temp_main.c
#include "variadic_functions.h"
#include <stdio.h>

int main(void) {
    printf("sum_them_all: %d\n", sum_them_all($sum_count, $sum_args));
    printf("print_numbers: ");
    print_numbers("$num_separator", $num_count, $num_args);
    printf("\nprint_strings: ");
    print_strings("$str_separator", $str_count, $str_args);
    printf("\nprint_all: ");
    print_all("$all_format"$all_args);
    printf("\n");
    return 0;
}
EOF

    # Compile
    mkdir -p exec
    implementation_files=$(ls [0-3]-*.c | grep -v '\-main.c')
    if gcc -Wall -Werror -Wextra -pedantic -std=gnu89 temp_main.c $implementation_files -o exec/user_example; then
        print_colored $GREEN "Compilation réussie. Résultat de l'exécution :"
        ./exec/user_example
        print_colored $YELLOW "\nExplication du fonctionnement :"
        print_colored $YELLOW "sum_them_all : A additionné $sum_count arguments pour un total affiché ci-dessus."
        print_colored $YELLOW "print_numbers : A affiché $num_count nombres séparés par '$num_separator'."
        print_colored $YELLOW "print_strings : A affiché $str_count chaînes séparées par '$str_separator'."
        print_colored $YELLOW "print_all : A affiché des données selon le format '$all_format'."
    else
        print_colored $RED "La compilation a échoué. Veuillez vérifier vos entrées et réessayer."
    fi

    # Clean up
    rm temp_main.c
}

# Function to run predefined examples
run_predefined_examples() {
    mkdir -p exec
    for file in [0-3]-main.c; do
        base=${file%-main.c}
        implementation_file=$(ls ${base}-*.c | grep -v "${file}")
        if [ -n "$implementation_file" ]; then
            compile_command="gcc -Wall -Werror -Wextra -pedantic -std=gnu89 $file $implementation_file -o exec/${base}"
            print_colored $BLUE "Commande de compilation pour $base :"
            echo "$compile_command"
            if eval $compile_command; then
                print_colored $GREEN "Exécution de ${base} :"
                ./exec/${base}
                echo ""
            else
                print_colored $RED "La compilation de ${base} a échoué."
            fi
        else
            print_colored $RED "Fichier d'implémentation pour $base non trouvé."
        fi
    done
}

# Main script
while true; do
    print_colored $GREEN "\nProgramme de démonstration des fonctions variadiques en C"
    print_colored $BLUE "Ce programme permet de tester différentes fonctions variadiques :"
    echo "  - sum_them_all : Somme tous les arguments passés"
    echo "  - print_numbers : Affiche une liste de nombres"
    echo "  - print_strings : Affiche une liste de chaînes de caractères"
    echo "  - print_all : Affiche différents types de données"
    echo ""

    read -p "Voulez-vous tester avec vos propres exemples ? (o/n) : " choice

    if [[ "$choice" == "o" || "$choice" == "O" ]]; then
        run_custom_example
    elif [[ "$choice" == "n" || "$choice" == "N" ]]; then
        run_predefined_examples
    else
        print_colored $RED "Choix non valide. Veuillez répondre par 'o' ou 'n'."
        continue
    fi

    read -p "Voulez-vous exécuter un autre exemple ? (o/n) : " continue_choice
    if [[ "$continue_choice" != "o" && "$continue_choice" != "O" ]]; then
        break
    fi
done

print_colored $GREEN "Merci d'avoir utilisé ce programme de démonstration !"