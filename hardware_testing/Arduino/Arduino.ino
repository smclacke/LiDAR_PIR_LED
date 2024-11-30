/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Arduino.ino                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: smclacke <smclacke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/30 17:36:48 by smclacke      #+#    #+#                 */
/*   Updated: 2024/11/30 21:12:05 by smclacke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <Arduino.h>
#include <WiFi.h>
#include <FastLED.h>
#include <wire.h>

const int	ledPin = 2;

void	setup()
{
	Serial.begin(115200);
	Serial.println("Testing Arduino setup");

	pinMode(ledPin, OUTPUT);
}

void	loop()
{
	digitalWrite(ledPin, HIGH);
	delay(1000);
	digitalWrite(ledPin, LOW);
	delay(1000);
}
