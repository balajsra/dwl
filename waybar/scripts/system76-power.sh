#!/usr/bin/env bash
profile="$(sudo system76-power profile | sed -z '$ s/\n$//' | tr '\n' '\r')"
graphics="$(sudo system76-power graphics)"
graphicsPower="$(sudo system76-power graphics power)"
chargeThresholds="$(sudo system76-power charge-thresholds | sed -z '$ s/\n$//' | tr '\n' '\r')"

echo '{"text":"󰢮 '$graphics'","tooltip":"󰢮\t'$graphics'\r󰐥\t'$graphicsPower'\r\r  Profile\r'$profile'\r\r󰚥 Charge Thresholds\r'$chargeThresholds'"}'
