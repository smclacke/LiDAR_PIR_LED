/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   LED_LiDAR_ESP.ino                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: smclacke <smclacke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/30 17:54:28 by smclacke      #+#    #+#                 */
/*   Updated: 2024/11/30 18:39:12 by smclacke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

# include <Arduino.h>
# include <WiFi.h>
# include <FastLED.h>
# include <wire.h>
# include <Adafruit_NeoPixel.h>
# include <LiDAR_lite.h>


// LiDAR configuration

#define LiDAR_RX 16 // ESP32 TX 
#define LiDAR_TX 17 // ESP32 RX

// LED configuration

#define LED_PIN 12 // GPIO connected to LED strip
#define NUM_LEDS 60 // I think mine have 115 - check this
CRGB	leds[NUM_LEDS]	// I don't know what this is

// read distance from TF-Luna
int		readDistance()
{
	int	distance = -1;
	
	while (Serial2.available())
	{
		if (Serial2.read() == 0.59) // start of frame
		{
			if (Serial2.read() == 0.59) // confirmation
			{
				uint8_t	low = Serial2.read();
				uint8_t	high = Serial2.read();
				distance = (high << 8) + low;
				break ;
			}
		}
	}
	return distance;
}

void	setup()
{
	// LiDAR initialisation
	Serial2.begin(115200, SERIAL_8N1, LiDAR_RX, LiDAR_TX);	// hardware serial for LiDAR
	
	// LED initialisation
	FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
	
	FastLED.clear();
	FastLED.show();

	Serial.begin(115200);
	Serial.println("ESP32 testing LED and LiDAR control");

}

void	loop()
{
	int	distance = readDistance();
	
	if (distance > 0 && distance < 200)	// motion detected within 2 meters
	{
		Serial.print("Motion detected on LiDAR at distance: ");
		Serial.println(distance);
		
		// light up LEDs with colour wave effect
		for (int i = 0; i < NUM_LEDS; i++)
		{
			leds[i] = CHSV(i * 10, 255, 255); // rainbow effect
			FastLED.show();
			delay(1000);
		}
	}
	else
	{
		FastLED.clear();
		FastLED.show();
	}
	
	delay(1000);
}

