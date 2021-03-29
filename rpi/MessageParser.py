#!/usr/bin/python3

class MessageParser():
    def parseMessage(msg):
        channels = []
        for i in range(0, len(msg)):
            channels.append(msg[i])
            # print("Channel value: ", channels[i])
        return channels            

if __name__ == "__main__":
    print(MessageParser.parseMessage("135"))
