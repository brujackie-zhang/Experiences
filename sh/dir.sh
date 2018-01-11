#!/bin/bash
read -t 30 -p "please input a directory:" dir
if [ -d $dir ];then
  echo "this is a directory!"
else 
  echo "this isn't a directory!"
fi
