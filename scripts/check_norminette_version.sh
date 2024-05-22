#!/bin/bash

check_norminette_version() {
    local current_version=$(norminette -v | awk '{print $2}')
    local base_version="3.3.51"

    if [[ $(echo -e "$base_version\n$current_version" | sort -V | head -n1) == $base_version ]]; then
        if [[ $current_version == $base_version ]]; then
            return 1
        else
            return 0
        fi
    else
        return 1
    fi
}

check_norminette_version