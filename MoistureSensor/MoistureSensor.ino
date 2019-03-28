#define sensorpin A1
#define in1 8
#define in2 9


//creating integers
int moisture;  
int moisturepercent;

void setup() {  
  // put your setup code here, to run once:

  //begin serial monitoring
  Serial.begin(9600);
}

void loop() {  
  // put your main code here, to run repeatedly:
moisture = analogRead(sensorpin); // Read moisture sensor value  
moisturepercent= map(moisture, 0, 1023, 0, 100); //changing to percent  
Serial.println(moisturepercent);//show serial monitor values  



}
