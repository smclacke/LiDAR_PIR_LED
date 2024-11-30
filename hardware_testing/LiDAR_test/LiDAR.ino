/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   LiDAR.ino                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: smclacke <smclacke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/30 17:35:09 by smclacke      #+#    #+#                 */
/*   Updated: 2024/11/30 21:50:23 by smclacke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <Arduino.h>
#include <WiFi.h>
#include <FastLED.h>
#include <wire.h>
#include <LiDAR_lite.h>

const int	lidarRX = 16;
const int	lidarTX = 17;
const int	ledPin = 2;

int	readDistance()
{
	int					distance = -1;
	unsigned long		startMillis = millis();

	while (Serial2.available())
	{
		if (millis() - startMillis > 1000) // i second timeout
		{
			Serial.println("Timeout waiting for LiDAR data");
			return -1;
		}
		if (Serial2.read() == 0x59) // assuming 0x59 is start byte
		{
			if (Serial2.read() == 0x59) // another 0x59 byte to confirm
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
	Serial2.begin(115200, SERIAL_8N1, lidarRX, lidarTX); // UART config instead of pinMode
	Serial.println("Testing LiDAR sensor");

	pinMode(ledPin, OUTPUT);
}

void	loop()
{
	int	distance = readDistance();

	if (distance > 0 && distance < 200)	// motion detected within 2 meters
	{
		Serial.print("Motion detected on LiDAR at distance: ");
		Serial.println(distance);

		digitalWrite(ledPin, HIGH);
		delay(500);
	}
	else
		digitalWrite(ledPin, LOW);

	delay(100);				// short delay to allow for rappid loops
}
