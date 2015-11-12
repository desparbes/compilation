#!/bin/bash

for i in test/*.c; 
do 
    gcc $i; 
    echo $i; 
done
