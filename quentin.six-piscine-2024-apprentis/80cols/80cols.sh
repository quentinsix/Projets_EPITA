#! /bin/sh

if [ $# -ne 2 ]; then
    echo "Usage: extchange.sh 'ext1' 'ext2'"
    exit 1
else
    for f in *.$1; do
        if [ -f $f ]; then
            name=$(echo "$f" | cut -f 1 -d '.')
            new="$name.$2"
            mv $f $new
            echo mv $f $new
        else
            exit 2
        fi
    done
    exit 0
fi
