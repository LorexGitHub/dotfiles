#!/bin/bash

static_info=$(cat /path/to/static-info.txt)
frames=(/home/david/.config/fastfetch/animations/teto-animations/teto-1/*.txt)

while true; do
  for frame in "${frames[@]}"; do
    clear
    echo "$static_info"
    cat "$frame"
    sleep 0.1
  done
done

