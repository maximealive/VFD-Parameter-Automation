# Variable Frequency Drive(VFD) Parameter-Automation

# Introduction
Use 380V- AC devices with a 220V-AC furniture in a smart and efficient way using a VFD and an arduino.<br><br>
<ins> NOTE </ins> <br>
be sure that you can change the 380V device connections to operate at 220V:<br>
![img_VFD](https://github.com/user-attachments/assets/c3fd1e39-4385-490a-90b2-c47ab7d462c4)

(useful link: https://www.quora.com/How-do-I-change-an-induction-motor-from-a-3-phase-380V-input-to-a-3-phase-220V-input )

## Hardware
VFD             |  Arduino (nano)             |5V 8-Channel Relay Module  |
:-------------------------:|:-------------------------:|:-------------------------:|
<img src="https://github.com/maximealive/VFD-Parameter-Automation/blob/main/images/vfd.jpg" width="100" height="100" />  |  <img src="https://github.com/maximealive/VFD-Parameter-Automation/blob/main/images/arduino.jpg" width="100" height="100" />  |<img src="https://github.com/maximealive/VFD-Parameter-Automation/blob/main/images/relays.jpg" width="100" height="100" />  | 

*I used the following VFD model: BuoQua 4KW 220V 5HP Trasformatore VFD Velocità Controllato Variatore Di Frequenza Inverter 5HP Frequenza Diver Inverter Professionale

ELEGOO 8 Channel DC 5V Modulo Relay con Accoppiatore Ottico per UNO R3 Mega 1280 DSP Arm PIC AVR Raspberry Pi

*Buttons: I needed to use 3 external buttons because I had to control 3 different motors. Each motor has specific parameters, like torque, RPM, etc., so each button sets the right motor's parameters 

*OBS*
- each relay is connected to a single VFD's button as shown in the figure below(the VFD keypad can be unmounted in order to reach the buttons and to solder wires and connect them to the realy module). RISCRIVERE QUESTA FRASE E VEDERE SE AGGIUNGERE IMMAGINE DEL PULSANTE

## Connections
fare disegno su mac tramite draw

## Software
Arduino IDE (VEDERE SE SCRIVERE VERSIONE)



DA AGGIUNGERE A "TODO" O COME MIGLIORAMENTI, ETC -> leggere file nella cartella zip "Francis_VFD.zip" che si trova nela repository privata.
