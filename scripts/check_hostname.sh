#!/bin/bash

hostname=$(hostname)
prefixes=("paul" "made" "bess")

found=false
for prefix in "${prefixes[@]}"; do
    if [[ $hostname == $prefix* ]]; then
        found=true
        break
    fi
done

if $found; then
    exit 1
else
    exit 0
fi