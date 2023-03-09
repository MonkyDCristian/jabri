# SoftwareSerial: https://docs.arduino.cc/learn/built-in-libraries/software-serial?queryID=567b9d5f7c13cf19558448db49f377dd&_gl=1*1j5g6j5*_ga*MTc5MTAxMzQ3MC4xNjc1MzQyMTM3*_ga_NEXN8H46L5*MTY3NjgzMjk1MC42LjEuMTY3NjgzNTExNS4wLjAuMA..#write
# pyserial: https://pythonhosted.org/pyserial/shortintro.html
# port setup: https://www.pcsuggest.com/linux-bluetooth-setup-hcitool-bluez/
# terminal: sudo rfcomm connect hci0 0A:E6:01:00:81:82 1

import serial, time

ser = serial.Serial('/dev/rfcomm0', 9600, timeout=1)  # open serial port

while True:
    line = ser.readline()
    print(line)

ser.close()             # close port


