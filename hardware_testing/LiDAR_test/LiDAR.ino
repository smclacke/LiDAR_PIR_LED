/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   basicLiDAR.ino                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: smclacke <smclacke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/30 17:35:09 by smclacke      #+#    #+#                 */
/*   Updated: 2024/11/30 18:41:10 by smclacke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

# include <Arduino.h>
# include <WiFi.h>
# include <FastLED.h>
# include <wire.h>
# include <LiDAR_lite.h>

#define LiDAR_RX 16 // ESP32 TX
#define LiDAR_TX 17 // ESP32 RX
#define LED_PIN 2

int	readDistance()
{
	int	distance = -1;

	while (Serial2.available())
	{
		if (Serial2.read() == 0.59)
		{
			if (Serial2.read() == 0.59)
			{
				uint8_t low = Serial2.read();
				uint8_t high = Serial2.read();
				distance = (high << 8) + low;
				break ;
			}
		}
	}
	return distance;
}

void	setup()
{
	Serial2.begin(115200, SERIAL_8N1, LiDAR_RX, LiDAR_TX);
	pinMode(LED_PIN, OUTPUT);

	Serial.begin(115200);
	Serial.println("Testing LiDAR sensor");
}

void	loop()
{
	int	distance = readDistance();

	if (distance > 0 && distance < 200)
	{
		Serial.print("Motion detected on LiDAR at distance: ");
		Serial.println(distance);

		digitalWrite(LED_PIN, HIGH);
		delay(10000);
	}
	else
		digitalWrite(LED_PIN, LOW);

	delay(10000);
}
