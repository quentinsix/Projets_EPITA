#!/bin/sh

while IFS="\n" read -r line
    do
        if echo "$line" | grep -qE '^[[:space:]]+$'; then
            echo "it is empty"
        elif echo "$line" | grep -qE '^[0-9]$'; then
            echo "it is a digit"
        elif echo "$line" | grep -qE '^[0-9]+$'; then
            echo "it is a number"
        elif echo "$line" | grep -qE '^[a-zA-Z]+$'; then
            echo "it is a word"
        elif echo "$line" | grep -qE '^[0-9a-zA-Z]+$'; then
            echo "it is an alphanum"
        elif echo "$line" | grep -qE '^+$'; then
            echo "it is empty"
        else
            echo "it is too complicated"
        fi
    done
