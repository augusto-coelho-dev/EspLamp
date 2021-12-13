# EspLamp
This project is a luminaire made with esp8266 in the Esp01 version with a NeoPixel led strip. Developed in c++ in Arduino IDE with connection to FireBase's RealTime Database receiving color data in rgba.

You will need the following materials:

1 x RGB ring light module;
1 x esp8266 osmo ws2812 rgb module;
1 x osmo module esp8266.

You will need the following libraries:
https://github.com/esp8266/Arduino
https://github.com/tzapu/WiFiManager
https://github.com/FirebaseExtended/firebase-arduino

I recommend that you read the specs about your Neopixel tape on the adafruit website for use in the project: https://learn.adafruit.com/adafruit-neopixel-uberguide

To connect Esp 01 to your wifi network, the WifiManager library is used, which generates a wifi network that, when connected to it, generates a page for you to configure.

To control the tape sending data to esp8266 it is necessary to create a project in Firebase, and inform the project Host and the authentication key in the code.
For next in your Firebase project in Realtime Database write a variable with name x with value: "rgba( X, X, X, X) pixel X" in the first part informs the color in rgba and the second part (pixe) informs the position of the led that will be changed, if you want to change the color of the entire ribbon just write "rgba( X, X, X, X)".
