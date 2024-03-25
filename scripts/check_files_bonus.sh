#!/bin/bash

R="\e[91m"
G="\e[92m"
Y="\e[93m"
BD="\e[1m"
X="\e[0m"

dir="../"
files=("libft.h" "Makefile")
targets=("all" "libft.a" "bonus" "clean" "fclean" "re")

check_lib_norme() {
    echo -e "\nStarting libft norme check..."
    if ! norminette -R CheckDefine ../libft.h > /dev/null 2>&1; then
        echo -e "${BD}Norminette libft:${X} ${R}ERROR${X}"
        return 1
    else
        echo -e "${BD}Norminette libft:${X} ${G}OK${X}"
        return 0
    fi
}

check_targets() {
    local makefile_targets=$(make -qpC .. | awk -F':' '/^[^.# ][^\t]*:/{print $1}')

    echo -e "\nStarting Makefile targets check..."
	for target in "${targets[@]}"; do
        found=false
        for make_target in $makefile_targets; do
            if [[ $make_target == "$target"* ]]; then
                found=true
                break
            fi
        done
        if ! $found; then
            echo -e "${BD}$target:${X} ${R}Missing${X}"
            return 1
        fi
    done
    echo -e "${BD}Makefile targets:${X} ${G}OK${X}"
    check_lib_norme
}

check_files() {
    echo -e "Starting file check..."
	for file in "${files[@]}"; do
		if [ -e "$dir/$file" ]; then
			echo -e "${BD}$file:${X} ${G}OK${X}"
		else
			echo -e "${BD}$file:${X} ${R}Missing${X}"
			return 1
		fi
	done
	check_targets
}

check_files