#!/bin/sh

if [ $# -ne 2 ]; then
    exit 1
fi
if [ $1 -lt 0 ]; then
    exit 1
fi
if [ $2 != "square" ] && [ $2 != "triangle" ]; then
    exit 1
fi

if [ $1 -eq 0 ]; then
    echo " _________________
|        _        |
|       | |       |
|       | |       |
|_______| |_______|"
    exit 0
else
    i=$1
    echo " _________________"
    while [ $i -ne 0 ]; do
        if [ $2 = "square" ]; then
            echo "|  ___       ___  |
| |_|_|     |_|_| |
| |_|_|     |_|_| |
|                 |"
        elif [ $2 = "triangle" ]; then
            echo "|                 |
|   /\       /\   |
|  /__\     /__\  |
|                 |"
        else
            exit 1
        fi
        i="$((i-1))"
    done
    echo "|        _        |
|       | |       |
|       | |       |
|_______| |_______|"
fi


exit 0
