/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   basicPIR.ino                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: smclacke <smclacke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/30 17:24:45 by smclacke      #+#    #+#                 */
/*   Updated: 2024/11/30 18:41:12 by smclacke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

# include <Arduino.h>
# include <WiFi.h>
# include <FastLED.h>
# include <wire.h>

#define PIR_PIN 13
#define LED_PIN 12

void	setup()
{
	pinMode(PIR_PIN, INPUT);
	pinMode(LED_PIN, OUTPUT);

	Serial.begin(115200);
	Serial.println("Testing PIR sensor");
}

void	loop()
{
	int		motionDetected = digitalRead(PIR_PIN);
	
	if (motionDetected == HIGH)
	{
		Serial.print("Motion detected on PIR");

		digialWrite(LED_PIN, HIGH);
		delay(10000);
	}
	else
		digialWrite(LED_PIN, LOW);
	
	delay(10000);
}
