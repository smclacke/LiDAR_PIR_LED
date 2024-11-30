/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ESP32.ino                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: smclacke <smclacke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/30 17:36:36 by smclacke      #+#    #+#                 */
/*   Updated: 2024/11/30 21:10:28 by smclacke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <Arduino.h>
#include <WiFi.h>
#include <wire.h>

const int	ledPin = 2;

void	setup()
{
	Serial.begin(115200);
	Serial.println("Testing ESP32 setup");
	
	pinMode(ledPin, OUTPUT);
}

void	loop()
{
	digitalWrite(LED_PIN, HIGH);
	delay(1000);				// 1 second
	digitalWrite(LED_PIN, LOW);
	delay(1000);				// 1 second
}
