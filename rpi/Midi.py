#!/usr/bin/python3

from os import confstr_names
import pygame.midi
import pygame.pypm as _pypm

class MidiConnection():
    _usedDevice = 0
    midiInterface = None

    def __init__(self):
        self.midiInterface = pygame.midi.init()
        # print(_pypm.CountDevices())
        for deviceNumber in range(0, _pypm.CountDevices()):
            listedDevice = pygame.midi.get_device_info(deviceNumber) 
            print(deviceNumber, listedDevice)
            if ("nanoKONTROL2 MIDI 1" in str(listedDevice[1])) and (listedDevice[2] == 1):
                self._usedDevice = deviceNumber
                self.midiInterface = pygame.midi.Input(self._usedDevice)
                print("New device id = ", self._usedDevice)     
    # def listenForMidi(self):



if __name__ == "__main__":
    MidiInterface = MidiConnection()
    # print(pygame.midi.get_default_input_id())
    while True:
        midinput = MidiInterface.midiInterface.read(1)
        if len(midinput) > 0:
            print(midinput)
