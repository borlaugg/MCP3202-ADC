# MCP3202-ADC
This repository contains the code required with instructions to interface MCP3202 with an Arduino.

## Interfacing ESP 3202 
The ADC is being used to convert analog data received from the pressure sensor aboard Matsya, to digital data. It sends this data through SPI 
to a Arduino Uno which forwards this message to the SBC through serial communication (UART). The datasheet is available in the directory `docs/MCP3202-datasheet.pdf`

## Making the connections
<p align="center">
  <img 
    width="600"
    height="300"
    src="https://github.com/borlaugg/MCP3202-ADC/blob/46203b452ba05923a22b74a7c747723d60139d57/docs/Portmap.png"
  >
</p>
The two channel ports CH0 and CH1 will be connected to the pressure sensor while $ D_{OUT} $, D_{IN}$, $\overline{CS}$ and the CLK pins correspond shoudl bemapped to the SPI lines of MISO, MOSI, $\overline{CS}$ and CLK respectively. 

## Receiving the data through SPI
<p align="center">
  <img 
    width="500"
    height="300"
    src="https://github.com/borlaugg/MCP3202-ADC/blob/46203b452ba05923a22b74a7c747723d60139d57/docs/Bitconfig.png"
  >
</p>
The ADC has two configurations for its input either single ended or differential.The pressure sensor being used has a differential output. This requires the first two bit that is to be transferred as 0 which should occur soon as the chip select line goes LOW (default HIGH). In the other case the first bit should be 1 and the second either 1 use CH1 or 0 to use CH0. Configuration of CH0 as +ve and CH1 as -ve polarity while taking differential input reuires the second bit to be 0 while 1 configures it to the reverse polarity. 
Next to set the data transfer in MSB format the third bit should be 1, while 0 configures it to transfer it in LSB format.
The Arduino command **RxData** = **SPI.transfer(0x2f)** configures it to differential mode, with MSB format. The variable RxData will store the received data in MSB format. Also SPI will be operated in mode 0 where it reads on rising clock edges and transmits on falling.

After this we send reading stored in RxData is sent to the SBC using the command **Serial.print(RxData)**.

## Configuring Arduino to receive
The MCP3202 requires a minimum clock frequency of 10kHz and a maximum of 1.8MHz at 5V Vdd. The command **SPISettings mySetting(1000000, MSBFIRST , SPI_MODE0)** configures to mode 0 with a clock frequency of 1MHz and reads MSB first. 
