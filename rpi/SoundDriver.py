#!/usr/bin/python3

import pygame.mixer
import time
from FileOperator import FileOperator

class SoundDriver():
    _channelsSounds = []
    mixer = 0
    fileOperator = None

    def __init__(self):
        # 1 is number of channels, should be bigger in the future to operate on 8 channels
        pygame.mixer.init(44100, -16, 1, 4096)
        self.fileOperator = FileOperator()
        self.loadSounds()

    def loadSounds(self):
        channelsPaths = []
        for channel in range(0, 4):
            channelContent = []
            # print(self.fileOperator.channelsContent[channel])
            for sound in self.fileOperator.channelsContent[channel]:
                # print(str( self.fileOperator.channelsPath + str(channel) + "/" + str(sound) ) )
                channelContent.append( str( self.fileOperator.channelsPath + str(channel) + "/" + str(sound) ) )
            
            self._channelsSounds.append([])
            for soundPath in channelContent:
                # print(soundPath)
                self._channelsSounds[channel].append(pygame.mixer.Sound(soundPath))
            
            # print(self._channelsSounds[channel][0])
            
            # print(channelContent)
            # print(channelContent[channel])
            # channelsPaths.append(channelContent)
            # self._channelsSounds.append(channelsPaths)
        # print(channelsPaths)

        
        # print(channelsPaths)

        # self._sounds.append(pygame.mixer.Sound("kit/kick.wav"))
        # self._sounds.append(pygame.mixer.Sound("kit/hhc.wav"))
        # self._sounds.append(pygame.mixer.Sound("kit/snare.wav"))
        # self._sounds.append(pygame.mixer.Sound("kit/clap.wav"))  

    def playSound(self, channelPlayback, sound):
        # print(self._channelsSounds)
        # print(channelPlayback, sound)
        self._channelsSounds[channelPlayback][sound].stop()
        self._channelsSounds[channelPlayback][sound].play()

    def getMaxChannelLenght(self, channelPlayback):
        # print(channelPlayback[0], type(channelPlayback[0]))
        # print(self._channelsSounds[channelPlayback[0]])
        # print(len(self._channelsSounds[channelPlayback[0]]))
        tempChannel = int(channelPlayback[0])
        return len(self._channelsSounds[tempChannel])

    def setSoundVolume(self, channel, volume):
        # print(volume/127)
        volumeChannel = 10
        if channel == 120: 
            volumeChannel = 0
        if channel == 121:
            volumeChannel = 1
        if channel == 122:
            volumeChannel = 2
        if channel == 123:
            volumeChannel = 3

        # print("new channel ", volumeChannel, " volume is ", volume)
        if volumeChannel != 10:
            for soundVolume in self._channelsSounds[volumeChannel]:
                soundVolume.set_volume(volume/127)

if __name__ == "__main__":
    soundDriver = SoundDriver()
    # soundDriver.playSound(0, 0)
    # soundDriver.setSoundVolume(0, 100)
    # soundDriver.setSoundVolume(3, 100)
    
    print(soundDriver.getMaxChannelLenght(1))
    print(soundDriver.getMaxChannelLenght(3))
    # for i in range(0, 4):
    #     soundDriver.playSound(0)
    #     time.sleep(1)