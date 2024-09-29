set shell := ["bash", "-c"]

# List just commands by default
default:
    @just --list

# Rebuild project
dwl-rebuild:
    sudo make clean all

# Run waybar with dwl configuration
dwl-launch-waybar:
    ./waybar/launch.sh
