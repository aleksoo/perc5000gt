#!/bin/bash
arduino-cli compile -b arduino:avr:mega ~/perc5000gt/arduino/ && arduino-cli upload --port /dev/ttyUSB0 --fqbn arduino:avr:mega:cpu=atmega2560 . -v
