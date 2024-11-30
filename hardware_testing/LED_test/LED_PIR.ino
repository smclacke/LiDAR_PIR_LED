/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   LED_PIR.ino                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: smclacke <smclacke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/30 17:34:37 by smclacke      #+#    #+#                 */
/*   Updated: 2024/11/30 21:13:28 by smclacke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/**
 * @todo fix to have uniform as everything else
 * check this works..
 */

#include <Arduino.h>
#include <WiFi.h>
#include <FastLED.h>
#include <wire.h>
#include <Adafruit_NeoPixel.h>
#include <LiDAR_lite.h>

// PIR configuration
#define PIR_PIN 13

// LED configuration
#define LED_PIN 12
#define NUM_LEDS 60
CRGB	leds[NUM_LEDS]

void	setup()
{
	pinMode(PIR_PIN, INPUT);

	FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
	
	FastLED.clear();
	FastLED.show();

	Serial.begin(115200);
 	Serial.println("Testing LED and PIR control");
}

void	loop()
{
	int		motionDetected = digitalRead(PIR_PIN);

	if (notionDetected == HIGH)
	{
		Serial.println("Motion detected on PIR");

		for (int i = 0; i < NUM_LEDS; i++)
		{
			leds[i] = CHSV(i * 10, 255, 255); // raindbow effect
			FastLED.show();
			delay(1000);
		}
	}
	else
	{	
		FastLED.clear();
		FastLED.show();
		delay(1000);
	}
}	
