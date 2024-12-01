
**IMPORTANT**
	
1) ONLY using ESP32 with MOSFET
		any arduino code stays in arduino directory

2) 
	#define LiDAR_RX 16 // ESP32 TX
	#define LiDAR_TX 17 // ESP32 RX

3) 
	for serial - must also init it iwith Serial.begin(baut rate)
	if using Serial2 (for LiDAR), still need the initial Serial.begin() call

4) MOSFET gate  = 14 - does pin matter? check which pin everytime!

5) CHSV = representation of an HSV pixel (hue, saturation, value (aka brightness))

------------------------------------------------------------------

**File setup** 

	.ino: This is the default file extension for sketches written in 
		the Arduino IDE, which is used for ESP32, Arduino boards, and others.

	.h: Used for header files, typically used to define functions, constants, 
		and variables that can be shared across different files.

	.cpp: C++ source files (can be used for more advanced Arduino/ESP32 projects).

------------------------------------------------------------------

**LiDAR**

	Hardware interface: UART USB CDC
	Default baudrate - 460800
	USB to serial converter - CP2102

	min measuring range - 5cm
	max measuring range - 1500cm

	power supply connector(s) - JST-GH (compatible) male (sensor)

	IO-connector(s) - JST-GH (compatible) male (sensor)

*important*
	No need to call pinMode() for the LiDAR RX and TX pins because Serial2.begin() takes care of configuring those pins for UART communication.
	Only use pinMode() for pins that you’re controlling as inputs or outputs, such as ledPin in your case.
	
------------------------------------------------------------------

**LEDs**

	for a led strip using FastLED, no need to pinMode(LED_PIN, OUTPUT) or digitalWrite(LED_PIN, HIGH), the library handles it all. just make sure addLEDs is in the set up and then use clear() show() etc

*important*
	Since you're using FastLED to control the LED strip (e.g., WS2812 LEDs), you don't need to call pinMode() for the LED pin because FastLED manages the pin configuration for you when you call FastLED.addLeds().
	The pinMode(ledPin, OUTPUT); is unnecessary, so you can remove it.

------------------------------------------------------------------

**ESP32 pinMode**

When using an ESP32 and calling ledcAttachPin(ledPin, ledChannel);, it is slightly different from pinMode(PIN, OUTPUT) but serves a similar purpose in the context of PWM control. Here's the distinction:

What ledcAttachPin Does
Purpose: This function attaches a GPIO pin (ledPin) to a specific LED control channel (ledChannel) for hardware PWM control on the ESP32.
Outcome: It allows the pin to be controlled by the ESP32's hardware PWM system, enabling smooth and efficient dimming or control of devices like LEDs.
Automatic Configuration: Once attached, the ESP32 internally configures the pin as an output (if it's not already). Thus, you don't need to explicitly call pinMode(PIN, OUTPUT).
How It Differs From pinMode
pinMode(PIN, OUTPUT) simply sets the pin to be an output but doesn't associate it with any specific functionality, such as PWM.
ledcAttachPin not only sets the pin as an output but also links it to a PWM channel, allowing you to control the pin with ledcWrite or similar functions.
In Summary
If you're using ledcAttachPin to control an LED or another PWM device on the ESP32, there's no need to call pinMode(PIN, OUTPUT) separately. The ledcAttachPin function implicitly handles it.

------------------------------------------------------------------

**#define pin vs const int pin**

	const int pin - c++ ( cleaner and better )

	#define - standard macro but without const etc
