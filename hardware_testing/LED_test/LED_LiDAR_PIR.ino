/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   LED_LiDAR_PIR_ESP.ino                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: smclacke <smclacke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/30 17:54:40 by smclacke      #+#    #+#                 */
/*   Updated: 2024/11/30 18:37:40 by smclacke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

# include <Arduino.h>
# include <WiFi.h>
# include <FastLED.h>
# include <wire.h>
# include <Adafruit_NeoPixel.h>
# include <LiDAR_lite.h>

// 	Serial.println("ESP32 testing LED PIR and LiDAR control");