#!/bin/bash
rate=$(df -h | grep "/dev/sda7" | awk '{print $5}' | cut -d "%" -f 1 )
if [ "$rate" -gt "14" ];then
  echo "rate use more!"
fi
