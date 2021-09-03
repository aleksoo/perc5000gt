#!/bin/bash
arduino-cli upload --port /dev/ttyUSB0 --fqbn arduino:avr:mega:cpu=atmega2560 . -v
