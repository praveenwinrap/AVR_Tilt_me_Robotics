@echo off
color f0
title AvrDude GUI Command Window
@echo.
@echo. trying to connect to device...
avrdude -p ATMEGA8 -c usbasp -P COM1  -U flash:w:"C:\Users\Premium\Desktop\Workshop_IOT_new\Workshop_IOT\codes\led_blinking\default\led_blinking.hex":i
avrdudeGUI.exe -done
pause