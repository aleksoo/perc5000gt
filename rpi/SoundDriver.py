#!/usr/bin/python3

import pygame.mixer
import time

class SoundDriver():
    _sounds = []
    mixer = 0

    def __init__(self):
        # 1 is number of channels, should be bigger in the future to operate on 8 channels
        pygame.mixer.init(48000, -16, 1, 1024)
        self.loadSounds()

    def loadSounds(self):
        self._sounds.append(pygame.mixer.Sound("kit/kick.wav"))
        self._sounds.append(pygame.mixer.Sound("kit/hhc.wav"))
        self._sounds.append(pygame.mixer.Sound("kit/snare.wav"))
        self._sounds.append(pygame.mixer.Sound("kit/clap.wav"))  

    def playSound(self, channelPlayback):
        self._sounds[channelPlayback].play()

if __name__ == "__main__":
    soundDriver = SoundDriver()
    for i in range(0, 4):
        soundDriver.playSound(0)
        time.sleep(1)