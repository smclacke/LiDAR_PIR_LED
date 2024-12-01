/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   LED_LiDAR_PIR.ino                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: smclacke <smclacke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/30 17:54:40 by smclacke      #+#    #+#                 */
/*   Updated: 2024/12/01 14:50:29 by smclacke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <Arduino.h>
#include <WiFi.h>
#include <FastLED.h>
#include <wire.h>
#include <Adafruit_NeoPixel.h>
#include <LiDAR_lite.h>
#include <crgb.h>

const int	lidarRX = 16;
const int	lidarTX = 17;
const int	pirPin = 13;
const int	ledPin = 12;
const int	mosfetPin = 14;

#define NUM_LEDS 60
CRGB	leds[NUM_LEDS];

int	readDistance()
{
	int					distance = -1;
	unsigned long		startMillis = millis();

	while (true)
	{
		if (millis() - startMillis > 1000) // 1 second timeout
		{
			Serial.println("Timeout waiting for LiDAR data");
			return -1;
		}
		if (Serial2.available() && Serial2.read() == 0x59) // assuming 0x59 is start byte
		{
			if (Serial2.available() && Serial2.read() == 0x59) // another 0x59 byte to confirm
			{
				uint8_t low = Serial2.read(); // read high byte
				uint8_t high = Serial2.read(); // read low byte
				distance = (high << 8) + low; // combine for full distance
				break ;
			}
		}
	}
	return distance;
}

void	setup()
{
	Serial.begin(115200);
	Serial2.begin(115200, SERIAL_8N1, lidarRX, lidarTX);
 	Serial.println("Testing PIR and LiDAR sensors with LED strip");

	pinMode(pirPin, INPUT);
	pinMode(mosfetPin, OUTPUT);
	digitalWrite(mosfetPin, LOW);
	FastLED.addLeds<WS2812, ledPin, GRB>(leds, NUM_LEDS);
	Serial.println("LiDAR sensor ready");
	
	FastLED.clear();
	FastLED.show();
	delay(30000); 				// allow 30 seconds for the PIR sensor to stabilize
	Serial.println("PIR sensor ready");
	
}

void	loop()
{
	int	motionDetected = digitalRead(pirPin);
	
	if (motionDetected == HIGH)
	{
		Serial.println("Motion detected on PIR");
		digitalWrite(mosfetPin, HIGH);
		
		int distance = readDistance();
		
		if (distance > 0 && distance < 200)
		{
			Serial.print("Motion detected on LiDAR at distance: ");
			Serial.println(distance);
			for (int i = 0; i < NUM_LEDS; i++)
			{
				leds[i] = CHSV(i * 10, 255, 255);
			}
			FastLED.show();
		}
		else
		{
			// motion but not close/detected my LiDAR
			// all LEDs set to a warm colour - not full effect
			FastLED.showColor(CRGB::Orange);
		}
	}
	else
	{
		digitalWrite(mosfetPin, LOW);
		FastLED.clear();
		FastLED.show();
	}
	delay(100);
}
