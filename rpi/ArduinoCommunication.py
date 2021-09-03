#!/usr/bin/python3

import serial
import time
from subprocess import getoutput
from time import sleep

class ArduinoCommunication():
    def __init__(self):
        self.connectArduino()

    def connectArduino(self):
        lock = True
        while lock:
            devicesList = str(getoutput('ls /dev/ | grep "ttyACM*\|ttyUSB*"')).split("\n")
            devicesList = list(filter(None, devicesList))
            print(devicesList)

            if len(devicesList) > 0:
                for device in devicesList:
                    targetDevice = "/dev/" + device
                    try:
                        self.arduinoSerial = serial.Serial(targetDevice, 9600)
                        self.arduinoSerial.baudrate=9600
                        lock = False
                        print("Device connected: ", device)
                        break
                    except serial.SerialException:
                        print("Error with device: ", device)
                        sleep(3)
            else:
                print("No devices!")
                sleep(3)

    def readSerialMsg(self):
        return str(self.arduinoSerial.read_until()).split("'", 1)[1].split("%", 1)[0]

    def isWaiting(self):
        try:
            return self.arduinoSerial.in_waiting
        except: serial.tim

if __name__ == "__main__":
    
    ardCom = ArduinoCommunication()

    while True:
        if ardCom.isWaiting() > 0:
            msg = ardCom.readSerialMsg()
            print(msg)