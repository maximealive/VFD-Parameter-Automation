# Variable Frequency Drive(VFD) Parameter-Automation

# Introduction
Use 380V- AC devices with a 220V-AC furniture in a smart and efficient way using a VFD and an arduino.<br><br>
<ins> NOTE </ins> <br>
be sure that you can change the 380V device connections to operate at 220V:<br>

<p align="center">
  <img width="410" height="250" src="https://github.com/user-attachments/assets/c3fd1e39-4385-490a-90b2-c47ab7d462c4">
</p>

## Hardware
VFD             |  Arduino (nano)             |5V 8-Channel Relay Module  |
:-------------------------:|:-------------------------:|:-------------------------:|
<img src="https://github.com/user-attachments/assets/d701328b-6d08-44ea-a0f6-a48747c7c25a" width="90" height="100" />  |  <img src="https://github.com/user-attachments/assets/fdc74bed-b436-4e63-b077-62585f0678e6" width="100" height="100" />  |<img src="https://github.com/user-attachments/assets/246276cd-cc9f-41c6-be08-7d0bec98bc00" width="100" height="100" />  | 

- VFD model: BuoQua 4KW 220V 5HP Trasformatore VFD Velocità Controllato Variatore Di Frequenza Inverter 5HP Frequenza Diver Inverter Professionale

- Buttons: three external buttons were necessary to control three separate motors driven by a VFD(in my case, one for a sander machine, another one for the planar and the last one for a Toupie machine). Please note that simultaneous control of multiple motors is feasible only if they are identical. Each motor necessitated unique parameter settings, including RPM, torque and so on.
- Wires/jumpers.

## Software
Arduino IDE (all version should be ok).

## Connections
Each relay is connected to a single button on the VFD, as shown. The VFD keypad can be unmounted to access the buttons for soldering wires and connecting them to the relay module.
<p align="center">
  <img src="https://github.com/user-attachments/assets/6eb61700-b27b-497e-a865-610379736898" width="300" height="300" />
</p>

<p align="center">
  <img width="300" height="380" src="https://github.com/user-attachments/assets/35de1f4c-8ab4-415b-973a-017fcb451f84">
</p>

## Result

<div align="center">
  <video src="https://github.com/user-attachments/assets/61a216fb-f2c9-4f5d-8ab0-22cea4845a12" width="400" />
</div>
* video speed 1.6x

## Issues/reference
- Take into account the logic of the relays, it depends if they have a dedicated power supply or not.
- Arduino pins during the boot could go high/low(following the boot processes), be carful about that to avoid unwanted behaviours.
- Switch bounce: https://docs.arduino.cc/built-in-examples/digital/Debounce/ (debouncing can be handled in hardware or software).
- https://www.quora.com/How-do-I-change-an-induction-motor-from-a-3-phase-380V-input-to-a-3-phase-220V-input.
- Ensure proper motor parameter configuration (e.g., voltage, frequency, torque, etc.) as incorrect values may lead to performance issues or equipment damage.

## ToDo
1) Implements remote control using one or more of the following implementations:<br>
   - TV remote controller -> accordingly add IR module.
   - Telegram Bot -> change Arduino, for example, with an ESP32 (https://github.com/maximealive/TelegramBot_ESP32-W5500; take into account that an internet connection is required).
   - Bluetooth -> bluetooth module and an Android/iOS application are required.

2) Give the possibility to set and store the motor's parameters -> add an LCD and something like a keypad.

3) Implement non-blocking delay (https://docs.arduino.cc/built-in-examples/digital/BlinkWithoutDelay/) - improve the code.
