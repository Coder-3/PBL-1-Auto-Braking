
 /***************************
  * Setting up the hardware *
  ***************************/
const int trigPin = 10;
const int ledPin = 9;
const int echoPin = 11;

long duration;
int distance;

 /*****************************************************
  * Function to vary brightness according to distance *
  *****************************************************/

int brightnesss(float inch)
{
    float dutyCycle = (pow(inch, -1) * 500);
    return int(dutyCycle);
}

void setup() 
{
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication
}
void loop() 
{
  /********************************************
   * Trigger the echo and receive back signal *
   *********************************************/
  digitalWrite(trigPin, LOW);
  digitalWrite(trigPin, HIGH);
  duration = pulseIn(echoPin, HIGH);
  
  distance= duration*0.034/2;
  int brightness = brightnesss(distance);
  analogWrite(ledPin, brightness);

}
