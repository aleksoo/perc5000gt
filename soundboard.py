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

seqLength = 8

def initGrid():
    global sndGrid
    sndGrid = [[1, 0, 0, 0, 1, 0, 0, 0], [0, 0, 1, 0, 0, 0, 1, 0], [0, 0, 0, 0, 1, 0, 0, 0], [0, 0, 0, 0, 0, 0, 1, 0]]
#    for channel in range(4):
#        sndGrid.append([0 for step in range(8)])

def init():
    global sndChannel, sndKick, sndSnare, sndHhc, sndClap
    pygame.mixer.init(48000, -16, 1, 1024)
    sndKick = pygame.mixer.Sound("kit/kick.wav")
    sndHhc = pygame.mixer.Sound("kit/hhc.wav")
    sndSnare = pygame.mixer.Sound("kit/snare.wav")
    sndClap = pygame.mixer.Sound("kit/clap.wav")
    
    for channelsInit in range(4):
        sndChannelList.append(pygame.mixer.Channel(channelsInit))
    initGrid()
    print("INIT complete")

def sequence():
    while True:
        for step in range(8):
            print(sndGrid[0][step])
            if sndGrid[0][step]:
                print("kick")
                sndChannelList[0].play(sndKick)
            if sndGrid[1][step]:
                print("hhat")
                sndChannelList[1].play(sndHhc)
            if sndGrid[2][step]:
                print("snare")
                sndChannelList[2].play(sndSnare)
#            if sndGrid[3][step]:
#                sndChannelList[3].play(sndClap)
            sleep(0.125)
        

def main():
    sequence()
#        while True:
#        sleep(1)
#        print("aa")
#        sndChannelList[0].play(sndKick)


if __name__ == "__main__":
    init()
    main()




