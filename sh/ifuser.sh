#!/bin/bash
test=$(env | grep "USER" | cut -d "=" -f 2)#读取环境变量并提取User行，user列
if [ "$test"=="brujackie-zhang" ];then
  echo "login user isn't root!"
fi

