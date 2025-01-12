/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Arduino.ino                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: smclacke <smclacke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/30 17:36:48 by smclacke      #+#    #+#                 */
/*   Updated: 2025/01/12 19:32:23 by SarahLouise   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

//#include <Arduino.h>
#include <WiFi.h>
#include <FastLED.h>
#include <wire.h>

const int	ledPin = 11;
const int	ledPin1 = 10;
const int	ledPin2 = 9;

void	setup()
{
	Serial.begin(115200);
	Serial.println("Testing Arduino setup");

	pinMode(ledPin, OUTPUT);
	pinMode(ledPin1, OUTPUT);
	pinMode(ledPin2, OUTPUT);
}

void	loop()
{
	digitalWrite(ledPin, HIGH);
	digitalWrite(ledPin1, LOW);
	digitalWrite(ledPin2, LOW);
	delay(1000);
	digitalWrite(ledPin, LOW);
	digitalWrite(ledPin1, HIGH);
	digitalWrite(ledPin2, LOW);
	delay(1000);
	digitalWrite(ledPin, LOW);
	digitalWrite(ledPin1, LOW);
	digitalWrite(ledPin2, HIGH);
	delay(1000);
}


// basic PIR test
//const int	ledPin = 11;
//const int	PIR = 5;
//const int	val = 0;
//const int	state = LOW;

//void setup()
//{
//	Serial.begin(115200);
//	Serial.println("Testing Arduino setup");

//	pinMode(ledPin, OUTPUT);
//	pinMode(PIR, INPUT);
//}

//void loop()
//{
//  val = digitalRead(sensor);

//  if (val == HIGH)
//  {  
//    digitalWrite(ledPin, HIGH);
//    delay(500);
//    if (state == LOW)
//    { 
//      Serial.println(" Motion detected");  
//      state = HIGH;  
//    } 
//  }
//  else
//  { 
//    digitalWrite(ledPin, LOW); 
//    delay(500);  
//    if (state == HIGH)
//    { 
//      Serial.println("The action/ motion has stopped"); 
//      state = LOW;  
//    }
//  } 
//}

// pulsating leds
  // for (int i = 0; i <= 255; i++) {
  //   analogWrite(ledPin, i);
  //   analogWrite(ledPin1, i + 5);
  //   analogWrite(ledPin2, i + 10);
  //   delay(10);
  
  // }
  // for (int i = 255; i >= 0; i--) {
  //   analogWrite(ledPin, i);
  //   analogWrite(ledPin1, i + 5);
  //   analogWrite(ledPin2, i + 10);
  //   delay(10);
  // }