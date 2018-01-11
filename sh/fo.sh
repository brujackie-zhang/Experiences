#!/bin/bash
ls *.txt > ls.log
ls *.sh >> ls.log
for i in $(cat ls.log)
  do
    echo $i
  done
