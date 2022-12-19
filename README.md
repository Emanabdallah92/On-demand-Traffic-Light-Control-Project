# On-demand-Traffic-Light-Control-Project

##System Description
On-demand Traffic Light Control is a project the consists of two modes that helps the 
pedestrians control the traffic to pass the road safely when demanded. The first mode 
controls the traffic light, while the second mode guide the pedestrian to pass the road. 
When, the pedestrian pushes the button as a request to pass the street. The systems stop 
the cars and guide the pedestrian to pass within the time limits, after that the cars will 
start to move again according to the traffic lights.

##System Design 
The system consists of 6 LEDS, one push button and an AVR CHIP (ATMEGA32). To 
represent the car’s mode that control the traffic we have 3 LEDs (RED, GREEN, YELLOW). 
We also have the push button that is used by the pedestrian to help them pass the 
street by stopping the cars and going to the pedestrian’s mode. Finally, we have the last 
3 LEDS (RED, GREEN, YELLOW) to represent the pedestrian’s traffic lights. The system is 
working at 1MHZ.
The system will consist mainly of three layers: Application, ECUAL, MCAL. The ECUAL will 
contain the LED and the button drivers. The MCAL will be composed of the following: 
DIO, timers, and interrupt drivers. In addition, there will be another layer that will store 
the AVR registers.

##System Constraints
• Pedestrian can cross the road for only 10 second every time they push 
the button.
• According to the software, cars will be stopped every 10 seconds.
