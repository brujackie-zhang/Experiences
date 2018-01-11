#!/bin/bash
read -t 30 -p "please input a number:" num1
read -t 30 -p "please input another number:" num2
read -t 30 -p "please input a operator:" oper
if [ -n "$num1" -a -n "$num2" -a -n "$oper" ];then
  test1=$(echo $num1 | sed 's/[0-9]//g')
  test2=$(echo $num2 | sed 's/[0-9]//g')
  if [ -z $test1 -a -z $test2 ];then
    if [ $oper=="+" ];then
      echo sum=$(($num1+$num2))
    elif [ $oper=="-" ];then
     echo sum=$(($num1-$num2))
    elif [ $oper=="*" ];then
     echo sum=$(($num1*$num2))
    else
     echo sum=$(($num1/$num2))
    fi
  else
    echo "operator error!"
  fi
else
  echo "number input error!"
fi

