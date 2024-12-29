#!/usr/bin/env bash
killall waybar || true

until /usr/bin/waybar \
    --config $HOME/.config/dwl/waybar/config.jsonc \
    --style $HOME/.config/dwl/waybar/style.css;
do
    if [ $? -ne 143 ]; then
        echo "Dwl Waybar stopped with exit code $?. Respawning..." >&2;
        sleep 1;
    else
        echo "Dwl Waybar manually killed with SIGTERM";
        break;
    fi
done
