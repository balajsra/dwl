set shell := ["bash", "-c"]

# List just commands by default
default:
    @just --list

# Rebuild project
dwl-rebuild:
    sudo make clean all

# Run waybar with dwl configuration
dwl-launch-waybar:
    /usr/bin/waybar -c /home/sravan/.config/dwl/waybar/config.jsonc -s /home/sravan/.config/dwl/waybar/style.css
