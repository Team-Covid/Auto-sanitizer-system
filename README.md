#AUTOMATIC HAND SANITIZER DISPENSER WITH IR THERMOMETER

In the effort to curb the spread of COVID-19, we propose the design of an automatic hand sanitizer with an IR thermometer. This portable device can be placed at the entrances of buildings, malls, and supermarkets. The use of the manual sanitizer has aroused the problem if an infected person were to touch the sanitizer bottle, then the next person also becomes infected. The automated sanitizer can automate this process, measuring the temperature of the person involved as well. This prevents the continuous spread of the disease and also reduces the need for personnel to check if a person can access the public facility.
#Materials 
The device will require the use of materials that can be sourced locally. The materials needed to make a fully operational device is as listed below.
1.		Submersible Water Valve  
2.		Arduino nano
3.		Buck converter
4.		Ultrasonic sensor 
5.		MLX90614 Sensor for IR thermometer
6.		Plastic container (to hold sanitizer)
7.		Copper clad Board
8.		Casing
9.		Li-Po Batteries
10.		Buzzer
11.		OLED display/LCD display

#OPERATION
The device is installed at the entrances to buildings, malls, supermarkets, offices, and hospitals. They will enable the person to sanitize his/her hands and, at the same, have his temperatures taken. This will do away with any contact that might otherwise be needed.
The device has an ultrasonic sensor that ensures that it only dispenses the sanitizer when the person places the hands below the outlet. The sensor is preset to ensure it dispenses when hands are placed a few centimeters from the outlet of the dispenser. Once the person has sanitized the hands, the sensor closes the solenoid valve stopping the flow of the sanitizer.
As the person sanitizes his hands, his face close to the IR thermometer to a range of 0 to 30 cm. The IR thermometers take body temperature readings. The IR sensor has preset values of temperature ranges for healthy individuals and ranges for individuals manifesting the COVID-19 symptoms. Once the temperature readings are taken, if the temperature falls in the range of a healthy person, the LED indicator remains green. If the temperature falls within the range of COVID-19 patient, the indicator light becomes Red and switches the Buzzer ON to notify the person-in-charge. With the RED indicator ON, and buzzer sound, it could indicate the person is manifesting symptoms of a COVID 19 disease, and necessary authorities can be contacted for action.
