#!/usr/bin/python3

class MessageParser():
    def parseMessage(msg):
        channels = []
        splittedChannels = msg.split('$')
        # print(splittedChannels)
        for splittedSingle in splittedChannels:
            if len(splittedSingle) < 2:
                continue
            channels.append(splittedSingle.split(':'))
            channels[-1][1] = int(channels[-1][1]) % 4

        return channels            

if __name__ == "__main__":
    print(MessageParser.parseMessage("0:0$1:399$3:0$%"))
