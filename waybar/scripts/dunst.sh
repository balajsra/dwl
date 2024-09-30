#!/usr/bin/env bash
isPaused=$(dunstctl is-paused)
notificationCount=$(dunstctl count history)

if [[ "$isPaused" == "true" ]]; then
    echo "󰂛 $notificationCount"
else
    echo "󰂚 $notificationCount"
fi
