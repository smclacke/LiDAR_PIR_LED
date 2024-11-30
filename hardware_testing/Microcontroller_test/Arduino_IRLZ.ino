/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Arduino_IRLZ.ino                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: smclacke <smclacke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/30 17:45:39 by smclacke      #+#    #+#                 */
/*   Updated: 2024/11/30 18:36:01 by smclacke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

# include <Arduino.h>

// brightness 0-255 | 255 full brightness

int		ledPin = 9;

void	setup()
{
	pinMode(ledPin, OUTPUT);
		Serial.println("Testing Arduino setup in combination with IRLZ44N");
}

void	loop()
{
	analogWrite(ledPin, 128);
	delay(10000);
	analogWrite(ledPin, 255);
	delay(10000);
}
