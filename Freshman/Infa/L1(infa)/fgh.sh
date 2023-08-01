#! /bin/bash

cat $1 |                   
tr -s '[:blank:][:punct:]'  '\012' | 
grep '^[A−Z][A-Za-z]*' |            
sort  |                    
uniq -c |                  
sort -n |                  
tail -n $2

