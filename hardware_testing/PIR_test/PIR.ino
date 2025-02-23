/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PIR.ino                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: smclacke <smclacke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/30 17:24:45 by smclacke      #+#    #+#                 */
/*   Updated: 2024/11/30 21:10:01 by smclacke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <Arduino.h>
#include <WiFi.h>
#include <wire.h>

const int	pirPin = 13;
const int	ledPin = 12;

void	setup()
{
	Serial.begin(115200);
	Serial.println("Testing PIR sensor");

	pinMode(pirPin, INPUT);
	pinMode(ledPin, OUTPUT);

	delay(30000); 				// allow 30 seconds for the PIR sensor to stabilize
	Serial.println("PIR sensor ready");
}

void	loop()
{
	int		motionDetected = digitalRead(pirPin);
	
	if (motionDetected == HIGH)
	{
		Serial.println("Motion detected on PIR");

		digitalWrite(ledPin, HIGH);
	}
	else
		digitalWrite(ledPin, LOW);
	
	delay(100);				// short delay to allow for rappid loops
}
