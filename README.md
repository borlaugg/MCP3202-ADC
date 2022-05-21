# MCP3202-ADC
This repository contains the code required with instructions to interface MCP3202 with an Arduino.

## Interfacing ESP 3202 
The ADC is being used to convert analog data received from the pressure sensor aboard Matsya, to digital data. It sends this data through SPI 
to a Arduino Uno which forwards this message to the SBC through serial communication (UART). The datasheet is available in the directory `docs/MCP3202-datasheet.pdf'
