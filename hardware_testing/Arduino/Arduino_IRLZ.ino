/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Arduino_IRLZ.ino                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: smclacke <smclacke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/30 17:45:39 by smclacke      #+#    #+#                 */
/*   Updated: 2024/11/30 21:12:01 by smclacke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <Arduino.h>

// brightness 0-255 | 255 full brightness

const int		ledPin = 2;

void	setup()
{
	Serial.begin(115200);
	Serial.println("Testing Arduino setup in combination with IRLZ44N");

	pinMode(ledPin, OUTPUT);
}

void	loop()
{
	analogWrite(ledPin, 128);
	delay(1000);
	analogWrite(ledPin, 255);
	delay(1000);
}

/** @note using a PWM-compatible pin and you have a proper connection to the MOSFET gate. 
 * Just ensure that the gate is connected to the Arduino PWM pin (e.g., pin 9), 
 * the source is grounded, and the drain is connected to the load (e.g., an LED or motor) 
 * and the power supply. 
 */
