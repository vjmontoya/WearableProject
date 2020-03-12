//define pins
#define echoPin 5
#define trigPin 6
#define motorPin 3


long duration;
double distance;


void setup() {
  //Serial Port begin
  Serial.begin(9600);

  //inputs and outputs
  pinMode (trigPin, OUTPUT);
  pinMode (echoPin, INPUT);
  pinMode (motorPin, OUTPUT);
  
  
  // put your setup code here, to run once:

}

int previousDistance = 0;
int recentDistance = 0;

void loop() {
    previousDistance = recentDistance;
    //Need to send a low pulse to get a clean high pulse
    
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    
    //does this even do anything
    delayMicroseconds(15);
    
    // Reads the echoPin, returns the sound wave travel time in microseconds
    
    duration = pulseIn(echoPin, HIGH);
    //delayMicroseconds(15);
    
    // Calculating the distance in cm
    distance = round((duration*.034)/2);
    recentDistance = distance;
    if(distance > 550) {
      Serial.print("Distance cm: ");
      Serial.println(550);
    } else {
      //loop();
    //} else {
    
     // Prints the distance on the Serial Monitor    
     Serial.print("Distance cm: ");
     Serial.println(distance);
    }
     
    
     delay(500);
    //Pause to let things settle
    
    //TODO: test in an open area to see if it makes it to 560 

}
