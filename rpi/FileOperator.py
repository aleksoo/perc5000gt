#!/usr/bin/python3

import os

class FileOperator():
    path = "/home/pi/perc5000gt/rpi/kit"
    channelsPath = "/home/pi/perc5000gt/rpi/kit/channel"
    channelsContent = [[], [], [], []]
    channelsSize = [0, 0, 0, 0]

    def __init__(self):
        self.updateChannelsContent()

    def updateChannelsContent(self):
        for channel in range(0, 4):
            self.channelsContent[channel] = os.listdir(self.path + "/channel" + str(channel))
            self.channelsSize[channel] = len(self.channelsContent[channel])
            # print("Channel " + str(channel) + ":")
            # print(self.channelsContent[channel])
            # print(self.channelsSize[channel])

if __name__ == "__main__":
    fileOperator = FileOperator()
    print(fileOperator.channelsContent)
