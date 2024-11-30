/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ESP32_IRLZ.ino                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: smclacke <smclacke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/30 17:47:48 by smclacke      #+#    #+#                 */
/*   Updated: 2024/11/30 21:10:33 by smclacke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <Arduino.h>
#include <WiFi.h>

const int	ledPin = 2;
const int	freq = 5000; // PWN frequency in Hz
const int	ledChannel = 0; // PWM channel (0 -15)
const int	resolution = 8; // PWM resolution 8-bit (0-255)

void	setup()
{
	Serial.begin(115200);
	Serial.println("Testing ESP32 setup in combination with IRLZ44N");
	
	pinMode(ledPin, OUTPUT);

	// configure PWM channel
	ledcSetup(ledChannel, freq, resolution);
	
	// attach channel to GPIO pin
	ledcAttachPin(ledPin, ledChannel);
}

void	loop()
{
	// set PWM duty cycle (brightness)
	ledcWrite(ledChannel, 128); // 50% brightness
	delay(1000);				// 1 second
	ledcWrite(ledChannel, 255); // 100% brightness
	delay(1000);				// 1 second
}
