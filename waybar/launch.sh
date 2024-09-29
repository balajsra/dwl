#!/usr/bin/env bash
killall waybar

sleep 5

/usr/bin/waybar \
    -c $HOME/.config/dwl/waybar/config.jsonc \
    -s $HOME/.config/dwl/waybar/style.css &
