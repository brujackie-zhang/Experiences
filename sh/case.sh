#!/bin/bash
read -t 30 -p "please input yes/no:" ch
case $ch in
  ("yes")
    echo "your choose is yes!"
    ;;
  ("no")
    echo "your choose is no!"
    ;;
  ("*")
    echo "error!"
    ;;
esac
