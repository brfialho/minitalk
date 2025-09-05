#!/bin/bash
color_code=95

while IFS= read -r line; do
  echo -e "\033[${color_code}m${line}\033[0m"
  sleep 0.04
done < art/art.txt