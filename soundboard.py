#!/usr/bin/python3

import pygame.mixer
from time import sleep
#import RPi.GPIO as GPIO
from sys import exit

#GPIO.setmode(GPIO.BCM)
#GPIO.setup(23, GPIO.IN)
#GPIO.setup(24, GPIO.IN)
#GPIO.setup(25, GPIO.IN)

sndChannelList = []
sndGrid = []
sndKick = 0
sndSnare = 0
sndHhc = 0
sndClap = 0


def initGrid(seqLength):
    global sndGrid
    for channel in range(4):
        sndGrid.append([0 for step in range(8)])

def init():
    global sndChannel, sndKick
    pygame.mixer.init(48000, -16, 1, 1024)
    sndKick = pygame.mixer.Sound("kit/kick.wav")
    sndHhc = pygame.mixer.Sound("kit/hhc.wav")
    sndSnare = pygame.mixer.Sound("kit/snare.wav")
    sndClap = pygame.mixer.Sound("kit/clap.wav")
    sndChannelList.append(pygame.mixer.Channel(1))
    initGrid(8)
    print("INIT complete")


def main():
    while True:
        sleep(1)
        print("aa")
        sndChannelList[0].play(sndKick)


if __name__ == "__main__":
    init()
    main()




