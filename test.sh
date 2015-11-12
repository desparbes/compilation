#!/bin/bash

for i in test/*.cmr; 
do 
    echo $i;
    build/parse $i; 
    head -n 1 $i;
    echo  ;
done
