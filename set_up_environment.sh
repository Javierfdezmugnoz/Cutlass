#!/bin/bash

# Remember to isolate the core where the taks to be measured is going to be executed
# Take a look to the guideline of the timing experiments

# It would be recommended disable the GUI
# systemctl set-default multi-user.target

# First time the user should use this command line
# sudo jetson_clocks --store

# Turn on fan (Jetson nano has not fan)
sudo jetson_clocks --fan

# Shown in the screen the nvp model in use
sudo nvpmodel -q

# Modify the nvp model (0 in our case)
sudo nvpmodel -m0


