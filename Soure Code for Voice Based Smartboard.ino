#include <LiquidCrystal.h>  //Importing of libraries
#include <SoftwareSerial.h>

LiquidCrystal lcd (4, 5, 6, 7, 8, 9); //initialization of LCD & Uno pins
SoftwareSerial mySerial (2,3);   //(RX, TX);

String val = "Waiting for Data";
String oldval;
String newval = "Waiting for data";
int i = 0;

void setup() 
{
  lcd.begin(16,2);
  mySerial.begin(9600);
  Serial.begin(9600);
  lcd.setCursor(0, 0);
  lcd.print("  Voice Based   ");
  lcd.setCursor(0, 1);
  lcd.print("   Smartboard     ");
  delay(5000);
  lcd.clear();
  lcd.print("  Welcome!  ");
  delay(3000);
}
void loop() 
{
  val = mySerial.readString(); //for reading the input data
  val.trim();                 //To remove garbage values if present
  Serial.println(val);
  
  if(val != oldval)            //To check if the data has new value
  {
    newval = val;
  }
  lcd.clear();
  lcd.setCursor(i, 0);
  lcd.print(newval);
  i++;
  
  if(i >= 15)
  {
    i = 0;
  }
  val = oldval;
   
}
