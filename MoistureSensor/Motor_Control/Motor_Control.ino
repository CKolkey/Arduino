//defining pins
#define in1 8
//#define in2 9
#define sensorpin A1

 //creating integers
int moisture;
int moisturepercent;

//Make LCD Work
#include <PCD8544.h>
static PCD8544 lcd;

void setup() {  

  // PCD8544-compatible displays may have a different resolution...
  lcd.begin(84, 48);

  //configure digital pins to OUTPUT
  pinMode(in1, OUTPUT);
//  pinMode(in2, OUTPUT);

  // Set initial rotation direction of motor
  digitalWrite(in1, HIGH);
//  digitalWrite(in2, HIGH);
  //begin serial monitoring
  Serial.begin(9600);

}
void loop() {  
moisture = analogRead(sensorpin); // Read moisture sensor value  
  moisturepercent= map(moisture, 0, 1023, 0, 100);
  Serial.println(moisturepercent);//show serial monitor values
  lcd.setCursor(0, 0);
  lcd.print(moisturepercent);
  lcd.print("\%");

//activating the motor if moisture is below 10%
if(moisturepercent < 10)  
{  
digitalWrite(in1, LOW);  
//digitalWrite(in2, LOW);  
}
else if (moisturepercent > 10)  
{
 digitalWrite(in1, HIGH);
 //digitalWrite(in2, LOW);
}

  delay(200);
  lcd.setCursor(0, 0);
  lcd.print("    ");
 // lcd.clear();

}
