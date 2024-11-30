/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   LED.ino                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: smclacke <smclacke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/30 18:48:20 by smclacke      #+#    #+#                 */
/*   Updated: 2024/11/30 21:11:45 by smclacke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <Arduino.h>
#include <WiFi.h>
#include <FastLED.h>
#include <wire.h>
#include <Adafruit_NeoPixel.h>

const int	ledPin = 12; // GPIO connected to LED strip

#define NUM_LEDS 60 // need to check how many mine have
CRGB	leds[NUM_LEDS]; // Declare the LED array for FastLED to control

void	setup()
{
	Serial.begin(115200);
	Serial.println("Testing LED strip");
	
	FastLED.addLeds<WS2812, ledPin, GRB>(leds, NUM_LEDS);
	
	FastLED.clear(); // turn all off initially
	FastLED.show();

}

void	loop()
{
	for (int i = 0; i < NUM_LEDS; i++)
	{
		leds[i] = CHSV(i * 10, 255, 255); // raindbow effect
		FastLED.show();
		delay(100);
	}

	FastLED.clear();
	FastLED.show();
	delay(100);					// short delay to allow for rappid loops
}
