#!/bin/bash
color_code=32

while IFS= read -r line; do
  echo -e "\033[${color_code}m${line}\033[0m"
  sleep 0.001
done < art/art_text.txt