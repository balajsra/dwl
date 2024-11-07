#!/usr/bin/env bash
mediaSourceIcon=$(`dirname $0`/get-media-source-icon.sh)
mediaStatus=$(playerctl --player=playerctld metadata 2>&1)

if [[ "$mediaStatus" == "No player could handle this command" ]]; then
        artist="N/A"
        title="N/A"
        album="N/A"
        status="N/A"
else
        artist=$(playerctl --player=playerctld metadata --format '{{ xesam:artist }}')
        title=$(playerctl --player=playerctld metadata --format '{{ xesam:title }}')
        album=$(playerctl --player=playerctld metadata --format '{{ xesam:album }}')
        status=$(playerctl --player=playerctld metadata --format '{{ status }}')

        if [[ $artist == "" ]]; then
            artist="N/A"
        fi

        if [[ $title == "" ]]; then
            title="N/A"
        fi

        if [[ $album == "" ]]; then
            album="N/A"
        fi

        if [[ $status == "" ]]; then
            status="N/A"
        fi
fi

echo '{"text":"'$mediaSourceIcon'","tooltip":"󰝚\t'${title//'"'/'\"'}'\r󰠃\t'${artist//'"'/'\"'}'\r󰀥\t'${album//'"'/'\"'}'\r󰐎\t'${status//'"'/'\"'}'"}'
