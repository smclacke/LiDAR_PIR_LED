/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   LiDAR.ino                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: smclacke <smclacke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/30 17:35:09 by smclacke      #+#    #+#                 */
/*   Updated: 2024/11/30 21:10:38 by smclacke      ########   odam.nl         */
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
	int	distance = -1;

	while (Serial2.available())
	{
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

	delay(30000); 				// allow 30 seconds for the PIR sensor to stabilize
	Serial.println("LiDAR sensor ready");
}

void	loop()
{
	int	distance = readDistance();

	if (distance > 0 && distance < 200)
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
