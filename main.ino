// Motor 1
int IN1 = 9;
int IN2 = 8;
int enA = 10;
// Motor 2
int IN3 = 7;
int IN4 = 6;
int enB = 5;
int LEDLinks = 2;
int LEDRechts = 4;

int SRWert = 0;
int SLWert = 0;
int SensorPinRechts = 1;
int SensorPinLinks = 0;
int MotorSpeed = 140;
int Threshold = 500;


void motorLinksVor(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(enA, MotorSpeed);
}
void motorLinksStopp(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
}
void motorRechtsVor(){
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(enB, MotorSpeed);
}
void motorRechtsStopp(){
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
void motorBeide(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void setup()
{
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(LEDLinks,OUTPUT);
  pinMode(LEDRechts,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  digitalWrite(11,HIGH); //SensorPin Power Supply
  digitalWrite(12,HIGH); //SensorPin Power Supply
  Serial.begin(9600);

}
void loop()
{

   SLWert = analogRead(SensorPinLinks);//Signal pin A0 on the board
   SRWert = analogRead(SensorPinRechts);//Signal pin A1 on the board
   Serial.print("SLWert ");
   Serial.print(SLWert);
   Serial.print("SRWert ");
   Serial.print(SRWert);
   Serial.println("");
  
   if ((SRWert > Threshold) && (SLWert < Threshold)) {
     digitalWrite(LEDRechts,HIGH);
     motorLinksVor();
     motorRechtsStopp();
     delay(10);
     digitalWrite(LEDRechts,LOW);
   }
   
   else if ((SRWert < Threshold) && (SLWert > Threshold)) {
     digitalWrite(LEDLinks,HIGH);
     motorRechtsVor();
     motorLinksStopp();
     delay(10);
     digitalWrite(LEDLinks,LOW);
   }
   
   else if ((SRWert > Threshold) && (SLWert > Threshold)) {
     motorLinksStopp();
     motorRechtsStopp(); 
   }
}


