

const int	ledPin = 11;
const int	ledPin1 = 10;
const int	ledPin2 = 9;

const int	PIR = 5;
int state = LOW;
int val = 0;

void setup()
{
	Serial.begin(115200);
	Serial.println("Testing Arduino setup");

  pinMode(ledPin, OUTPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);

  pinMode(PIR, INPUT);
}

void loop()
{
  val = 0; 
  digitalWrite(ledPin, LOW); 
  delay(100);

  val = digitalRead(PIR);

  if (val == HIGH)
  {  
    for (int i = 0; i <= 255; i++)
    {
      analogWrite(ledPin, i);
      analogWrite(ledPin1, i + 5);
      analogWrite(ledPin2, i + 10);
      delay(20);
    }
  }
  if (val == LOW)
  { 
    for (int i = 255; i >= 0; i--)
    {
      analogWrite(ledPin, i);
      analogWrite(ledPin1, i + 5);
      analogWrite(ledPin2, i + 10);
      delay(20);
    }
  }
}

  
