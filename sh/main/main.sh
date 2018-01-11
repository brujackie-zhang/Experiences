#!/bin/bash
re=$(tput sgr0)
declare -A ssha
i=0
num=""
for script_file in $(ls -I "main.sh")
do
  echo -e '\e[1;37m' "the script:" ${i} '==>' ${re} ${script_file}
  ssha[$i]=${script_file}
  num="$num | $i |"
  i=$(($i+1))
done
echo $num
