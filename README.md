# Variable Frequency Drive(VFD) Parameter-Automation

# Introduction
Use 380V- AC devices with a 220V-AC furniture in a smart and efficient way using a VFD and an arduino.<br><br>
<ins> NOTE </ins> <br>
be sure that you can change the 380V device connections to operate at 220V (useful link: https://www.quora.com/How-do-I-change-an-induction-motor-from-a-3-phase-380V-input-to-a-3-phase-220V-input):<br>

<p align="center">
  <img width="460" height="300" src="https://github.com/user-attachments/assets/c3fd1e39-4385-490a-90b2-c47ab7d462c4">
</p>

## Hardware
VFD             |  Arduino (nano)             |5V 8-Channel Relay Module  |
:-------------------------:|:-------------------------:|:-------------------------:|
<img src="https://github.com/maximealive/VFD-Parameter-Automation/blob/main/images/vfd.jpg" width="100" height="100" />  |  <img src="https://github.com/maximealive/VFD-Parameter-Automation/blob/main/images/arduino.jpg" width="100" height="100" />  |<img src="https://github.com/maximealive/VFD-Parameter-Automation/blob/main/images/relays.jpg" width="100" height="100" />  | 

\* I used the following VFD model: BuoQua 4KW 220V 5HP Trasformatore VFD Velocità Controllato Variatore Di Frequenza Inverter 5HP Frequenza Diver Inverter Professionale

** Buttons: three external buttons were necessary to control three separate motors driven by a VFD. Please note that simultaneous control of multiple motors is feasible only if they are identical. Each motor necessitated unique parameter settings, including RPM, torque and so on. 

## Connections
fare disegno su mac tramite draw

\* Each relay is connected to a single button on the VFD, as shown in the figure below. The VFD keypad can be unmounted to access the buttons for soldering wires and connecting them to the relay module:

<p align="center">
  <img width="300" height="380" src="https://github.com/user-attachments/assets/35de1f4c-8ab4-415b-973a-017fcb451f84">
</p>

## Software
Arduino IDE<br>
\* consider the logic of the relays, it depends if they have a dedicated power supply or not

## ToDo
1) Implements remote control using one or more of the following implementations:<br>
   - TV remote controller -> accordingly add IR module
   - Telegram Bot -> change Arduino, for example, with an ESP32 (https://github.com/maximealive/TelegramBot_ESP32-W5500; take into account that an internet connection is required)
   - Bluetooth -> bluetooth module and an Android/iOS application are required

2) Give the possibility to set and store the motor's parameters -> add an LCD and something like a keypad

3) Implement non-blocking delay (https://docs.arduino.cc/built-in-examples/digital/BlinkWithoutDelay/)
