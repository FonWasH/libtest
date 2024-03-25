#!/bin/bash

R="\e[91m"
G="\e[92m"
Y="\e[93m"
BD="\e[1m"
DM="\e[2m\e[3m"
X="\e[0m"

dir="../"
files=("libft.h" "Makefile")
targets=("all" "libft.a" "clean" "fclean" "re")
flags=("-Wall" "-Wextra" "-Werror")

echo -e "Starting check..."

check_lib_norme() {
    if ! norminette -R CheckDefine ../libft.h > /dev/null 2>&1; then
        echo -e "${BD}Norminette libft:${X} ${R}ERROR${X}"
        return 1
    else
        echo -e "${BD}Norminette libft:${X} ${G}OK${X}"
        return 0
    fi
}

check_compile_flags() {
    local makefile_flags=$(make -qpC .. | awk '/^CFLAGS/{for (i=3; i<=NF; i++) print $i}')

    for flag in "${flags[@]}"; do
        found=false
        for make_flag in $makefile_flags; do
            if [[ $make_flag == "$flag"* ]]; then
                found=true
                break
            fi
        done
        if ! $found; then
            echo -e "${BD}Compilation flag:${X} ${DM}$flag${X} ${R}MISSING${X}"
            return 1
        fi
    done
    echo -e "${BD}Compilation flag:${X} ${G}OK${X}"
    check_lib_norme
}

check_targets() {
    local makefile_targets=$(make -qpC .. | awk -F':' '/^[^.# ][^\t]*:/{print $1}')

	for target in "${targets[@]}"; do
        found=false
        for make_target in $makefile_targets; do
            if [[ $make_target == "$target"* ]]; then
                found=true
                break
            fi
        done
        if ! $found; then
            echo -e "${BD}Makefile targets:${X} ${DM}$target${X} ${R}MISSING${X}"
            return 1
        fi
    done
    echo -e "${BD}Makefile targets:${X} ${G}OK${X}"
    check_compile_flags
}

check_files() {
	for file in "${files[@]}"; do
		if [ -e "$dir/$file" ]; then
			echo -e "${BD}$file:${X} ${G}OK${X}"
		else
			echo -e "${BD}$file:${X} ${R}MISSING${X}"
			return 1
		fi
	done
	check_targets
}

check_files