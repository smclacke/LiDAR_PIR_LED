/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   testArduino.ino                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: smclacke <smclacke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/30 17:36:48 by smclacke      #+#    #+#                 */
/*   Updated: 2024/11/30 17:38:52 by smclacke      ########   odam.nl         */
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
}

void	loop()
{
	digitalWrite(LED_PIN, HIGH);
	delay(1000);
	digitalWrite(LED_PIN, LOW);
	delay(1000);
}

