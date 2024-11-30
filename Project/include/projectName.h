/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   projectName.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: smclacke <smclacke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/30 17:31:37 by smclacke      #+#    #+#                 */
/*   Updated: 2024/11/30 21:10:14 by smclacke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// may not need some/most of these if included in IDE
 
#include <Arduino.h>			// all basic arduino functions
#include <WiFi.h>				// WiFi connectivity with ESP32
#include <FastLED.h>			// LED functions and effects
#include <wire.h>				// if applicable, for 12C communication with LiDAR
#include <Adafruit_NeoPixel.h>	// for LED effects
#include <LiDAR_lite.h>		// for LiDAR functionality
#include <HardwareSerial.h>		// for communication with UART device (LiDAR)
#include <TF_Luna.h>			// if applicable for LiDAR functionality

