#!/bin/bash

for i in test/*.cmr; 
do 
    echo $i;
    sed '1q;d' $i;
    build/parse $i;
    base=$(basename $i .cmr);
    llfile='build/'$base'.ll';
    lli $llfile;
    sed '2q;d' $i;
    echo  ;
done
