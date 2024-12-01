/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   src1.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: smclacke <smclacke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/30 17:33:28 by smclacke      #+#    #+#                 */
/*   Updated: 2024/12/01 14:39:31 by smclacke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/projectName.h"

/** 
 * @brief	Read distance from LiDAR sensor when motion is detected
 * 			- Timeouts after 1 second if no data received
 * 			- If motion detected, second check to confirm
 *  		- Read high byte, read low byte, combine for full distance
 * 			- Break while loop and return distance
 * 
 * @note	ALways check 0x59 is the correct starting byte
 * 
 * @return	int distance detected from LiDAR
 * 			if -1, timeout or error has occured
 * 			if >= 0, distance has been calculated based on the received data
 */
int	readDistance()
{
	int					distance = -1;
	unsigned long		startMillis = millis();

	while (true)
	{
		if (millis() - startMillis > 1000)
		{
			Serial.println("Timeout waiting for LiDAR data");
			return -1;
		}
		if (Serial2.available() && Serial2.read() == 0x59)
		{
			if (Serial2.available() && Serial2.read() == 0x59)
			{
				uint8_t low = Serial2.read();
				uint8_t high = Serial2.read();
				distance = (high << 8) + low;
				break ;
			}
		}
	}
	return distance;
}
