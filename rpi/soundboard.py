#!/usr/bin/python3

import pygame.mixer
from time import sleep
from sys import exit

from ArduinoCommunication import ArduinoCommunication
from MessageParser import MessageParser
from SoundDriver import SoundDriver

if __name__ == "__main__":
    ardCom = ArduinoCommunication()
    soundDriver = SoundDriver()
    x = 0
    while True:
        if ardCom.isWaiting() > 0:
            msg = MessageParser.parseMessage(ardCom.readSerialMsg())
            print(msg)
            for channelPlayback in msg:
            #    print("value: ", channelPlayback)
                soundDriver.playSound(int(channelPlayback))