/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   testESP32.ino                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: smclacke <smclacke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/30 17:36:36 by smclacke      #+#    #+#                 */
/*   Updated: 2024/11/30 18:36:16 by smclacke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

# include <Arduino.h>
# include <WiFi.h>
# include <FastLED.h>
# include <wire.h>

#define LED_PIN 2

void	setup()
{
	pinMode(LED_PIN, OUTPUT);
	Serial.println("Testing ESP32 setup");
}

void	loop()
{
	digitalWrite(LED_PIN, HIGH);
	delay(1000);
	digitalWrite(LED_PIN, LOW);
	delay(1000);
}

