#!/bin/bash

declare -A executable_whitelists
executable_whitelists["../ft_isalpha.o"]=""
executable_whitelists["../ft_isdigit.o"]=""
executable_whitelists["../ft_isalnum.o"]=""
executable_whitelists["../t_isascii.o"]=""
executable_whitelists["../ft_isprint.o"]=""
executable_whitelists["../ft_strlen.o"]=""
executable_whitelists["../ft_memset.o"]=""
executable_whitelists["../ft_bzero.o"]=""
executable_whitelists["../ft_memcpy.o"]=""
executable_whitelists["../ft_memmove.o"]=""
executable_whitelists["../ft_strlcpy.o"]=""
executable_whitelists["../ft_strlcat.o"]=""
executable_whitelists["../ft_tolower.o"]=""
executable_whitelists["../ft_toupper.o"]=""
executable_whitelists["../ft_strchr.o"]=""
executable_whitelists["../ft_strrchr.o"]=""
executable_whitelists["../ft_strncmp.o"]=""
executable_whitelists["../ft_memchr.o"]=""
executable_whitelists["../ft_memcmp.o"]=""
executable_whitelists["../ft_strnstr.o"]=""
executable_whitelists["../ft_atoi.o"]=""
executable_whitelists["../ft_calloc.o"]="malloc"
executable_whitelists["../ft_strdup.o"]="malloc"
executable_whitelists["../ft_substr.o"]="malloc"
executable_whitelists["../ft_strjoin.o"]="malloc"
executable_whitelists["../ft_strtrim.o"]="malloc"
executable_whitelists["../ft_split.o"]="malloc,free"
executable_whitelists["../ft_itoa.o"]="malloc"
executable_whitelists["../ft_strmapi.o"]="malloc"
executable_whitelists["../ft_striteri.o"]=""
executable_whitelists["../ft_putchar_fd.o"]="write"
executable_whitelists["../ft_putstr_fd.o"]="write"
executable_whitelists["../ft_putendl_fd.o"]="write"
executable_whitelists["../ft_putnbr_fd.o"]="write"
executable_whitelists["../ft_lstnew.o"]="malloc"
executable_whitelists["../ft_lstadd_front.o"]=""
executable_whitelists["../ft_lstsize.o"]=""
executable_whitelists["../ft_lstlast.o"]=""
executable_whitelists["../ft_lstadd_back.o"]=""
executable_whitelists["../ft_lstdelone.o"]="free"
executable_whitelists["../ft_lstclear.o"]="free"
executable_whitelists["../ft_lstiter.o"]=""
executable_whitelists["../ft_lstmap.o"]="malloc,free"

check_sysfunc() {
    local file="$1"
    local whitelist_str="${executable_whitelists[$file]}"
    local whitelist=()
    local symbols=$(nm "$file" | grep ' U ' | awk '{print $2}')
    local forbidden_calls=()
    
    if [ -n "$whitelist_str" ]; then
        IFS=',' read -r -a whitelist <<< "$whitelist_str"
    fi
    for symbol in $symbols; do
        local found=0
		if [[ "$symbol" == ft_* ]]; then
            continue
        fi
        for allowed_call in "${whitelist[@]}"; do
            if [ "$symbol" == "$allowed_call" ]; then
                found=1
                break
            fi
        done
        if [ $found -eq 0 ]; then
            forbidden_calls+=("$symbol")
        fi
    done
    if [ ${#forbidden_calls[@]} -eq 0 ]; then
        echo "Forbidden system function calls: OK"
        return 0
    else
        echo "Forbidden system function calls detected:"
        for forbidden_call in "${forbidden_calls[@]}"; do
            echo "- $forbidden_call"
        done
        return 1
    fi
}

check_sysfunc "$1"