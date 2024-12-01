/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   LED_PIR.ino                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: smclacke <smclacke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/30 17:34:37 by smclacke      #+#    #+#                 */
/*   Updated: 2024/12/01 14:50:40 by smclacke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <Arduino.h>
#include <WiFi.h>
#include <FastLED.h>
#include <wire.h>
#include <Adafruit_NeoPixel.h>
#include <LiDAR_lite.h>
#include <crgb.h>

const int	pirPin = 13;
const int	ledPin = 12;
const int	mosfetPin = 14;

#define NUM_LEDS 60
CRGB	leds[NUM_LEDS]; // Declare the LED array for FastLED to control

void	setup()
{
	Serial.begin(115200);
 	Serial.println("Testing PIR sensor with LED strip");
	
	pinMode(pirPin, INPUT);
	pinMode(mosfetPin, OUTPUT);
	digitalWrite(mosfetPin, LOW);
	FastLED.addLeds<WS2812, ledPin, GRB>(leds, NUM_LEDS);
	
	FastLED.clear();
	FastLED.show();
	delay(30000); 				// allow 30 seconds for the PIR sensor to stabilize
	Serial.println("PIR sensor ready");

}

void	loop()
{
	int		motionDetected = digitalRead(pirPin);

	if (motionDetected == HIGH)
	{
		Serial.println("Motion detected on PIR");
		digitalWrite(mosfetPin, HIGH); // turn on MOSFET to power the LED strip

		for (int i = 0; i < NUM_LEDS; i++)
		{
			leds[i] = CHSV(i * 10, 255, 255);
		}
		FastLED.show();
	}
	else
	{	
		digitalWrite(mosfetPin, LOW); // turn off MOSFET to cut power to the LED strip
		FastLED.clear();
		FastLED.show();
	}
	delay(100);
}	
