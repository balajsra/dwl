#!/usr/bin/env bash
killall waybar

/usr/bin/waybar \
    -c $HOME/.config/dwl/waybar/config.jsonc \
    -s $HOME/.config/dwl/waybar/style.css &
