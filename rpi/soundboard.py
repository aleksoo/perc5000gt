#!/usr/bin/python3

import pygame.mixer
from time import sleep
from sys import exit

from ArduinoCommunication import ArduinoCommunication
from MessageParser import MessageParser
from SoundDriver import SoundDriver
from Midi import MidiConnection

if __name__ == "__main__":
    ardCom = ArduinoCommunication()
    soundDriver = SoundDriver()
    midiInterface = MidiConnection()
    channelsVolumes = [127, 127, 127, 127]
    x = 0
    while True:

        # tutaj czytanie midi
        midinput = midiInterface.midiInterface.read(1)
        if len(midinput) > 0:
            midiMessage = midiInterface.getMidiChannelVolume(midinput)  
            soundDriver.setSoundVolume(midiMessage[0], midiMessage[1])


        if ardCom.isWaiting() > 0:
            msg = MessageParser.parseMessage(ardCom.readSerialMsg())
            # print(msg)
            for channelPlayback in msg:
            #    print("value: ", channelPlayback)
                soundDriver.playSound(int(channelPlayback)) # TODO: poprawic odbior parsowania message