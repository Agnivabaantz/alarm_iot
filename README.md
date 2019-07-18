# alarm_iot
Anti-Theft Alarm System using NodeMCU microcontroller and PIR sensors.
CPP files DHT.cpp and Gsender.cpp are imported and implemented by MotionSensor.ino
Arduino is used as an interface to burn codes into the NODEMCU microcontroller
Hardware requirements:: PIR sensors,NodeMCU microcontroller , Arduino UNO , electric buzzer , jumper wires
Objective::
          To warn the owner of the house incase of any trespassers using PIR motion sensors to detect the motion
          and feed the output as input to the system . If output signal of true state is recieved , ESP8266WiFi
          header functions are used to maintain connectivity using NodeMCU WiFi and Gsender.cpp code is used to
          send a mail to the owner's gmail account repeatedly every 5 minutes incase of breach. An electric buzzer is
          also used to notify the local area as an alarm.
