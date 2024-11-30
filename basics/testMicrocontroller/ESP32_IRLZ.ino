/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ESP32_IRLZ.ino                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: smclacke <smclacke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/30 17:47:48 by smclacke      #+#    #+#                 */
/*   Updated: 2024/11/30 18:19:43 by smclacke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

# include <Arduino.h>
# include <WiFi.h>

// brightness 0-255 | 255 full brightness

const int	ledPin = 9;

const int	freq = 5000; // Hz
const int	ledChannel = 0; // PWM channel (0 -15)
const int	resolution = 8; // 8-bit (0-255)

void	setup()
{
	// configure PWM channel
	ledcSetup(ledChannel, freq, resolution);
	
	// attach channel to GPIO pin
	ledAttachPin(ledPin, ledChannel);
}

void	loop()
{
	// set PWM duty cycle (brightness)
	ledcWrite(ledChannel, 128); // 50% brightness

	delay(1000);
	
	ledcWrite(ledChannel, 255); // 100% brightness
	
	delay(1000);
}

