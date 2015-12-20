#!/bin/bash

for i in test/*.cmr; 
do 
    echo $i;
    head -n 2 $i;
    build/parse $i;
    base=$(basename $i .cmr);
    llfile='build/'$base'.ll';
    llc $llfile;
    echo  ;
done
