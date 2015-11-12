#!/bin/bash

for i in test/*.cmr; 
do 
    build/parse $i; 
    echo $i; 
done
