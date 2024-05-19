#!/bin/bash

check_hostname() {
    local hostname=$(hostname)
    local prefixes=("paul" "made" "bess")

    for prefix in "${prefixes[@]}"; do
        [[ $hostname == $prefix* ]] && return 1
    done
    return 0
}

check_hostname