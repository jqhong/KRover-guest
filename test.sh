#!/bin/bash

INDEX="0"

while true
do
    let "INDEX=INDEX+1"
    echo "$INDEX round testing"
    ./hello
    echo " =============== "
    echo " "
done
