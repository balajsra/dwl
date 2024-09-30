#!/usr/bin/env bash
mediaStatus=$(playerctl --player=playerctld metadata 2>&1)

if [[ "$mediaStatus" == "No player could handle this command" ]]; then
    echo "N/A"
else
    status=$(playerctl --player=playerctld metadata --format '{{ status }}')

    echo $status
fi
