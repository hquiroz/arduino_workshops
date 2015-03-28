//initializes/defines the output pin of the LM335 temperature sensor
int ledPins[] = { 
  2, 3, 4, 5, 6, 7 }; // an array of pin numbers to which LEDs are attached

void setup()
{
Serial.begin(9600);//Begin the serial connection between Arduino and Computer

// Make pins 2, 3, 4, 5, 6, & 7 outputs
for (int thisPin = 0; thisPin < 6; thisPin++) 
    pinMode(ledPins[thisPin], OUTPUT);
}

//main loop
void loop()
{

//This turns voltage reading from the LM335 sensor into degrees celsius
int rawvoltage= analogRead(A0);
float millivolts= (rawvoltage/1024.0) * 5000;
float kelvin= (millivolts/10);
int celsius= kelvin - 273.15;


//Uncomment the following to view temperature in Celsius
//Serial.print(celsius);
//Serial.println(" degrees Celsius");


 //Temperature bandwidth is currently 25 - 30
 //check serial monitor for upper and lower thresholds
 
 if (celsius >= 25 ) //If temperature is higher than or equal to 25 degrees turn on first LED
  {
     digitalWrite (ledPins[0], HIGH);//turn on first led
  }

 if (celsius >= 26) //If temperature is higher than or equal to 26 degrees turn on first LED
  {
      digitalWrite (ledPins[1], HIGH);//turn on second led
  }
 
 if (celsius >= 27) //If temperature is higher than or equal to 27 degrees turn on first LED
  {
    digitalWrite (ledPins[2], HIGH);//turn on third led
  }
  
 if (celsius >= 28) //If temperature is higher than or equal to 28 degrees turn on first LED
  {  
    digitalWrite (ledPins[3], HIGH);//turn on fourth led
  }
 
 if (celsius >=29) //If temperature is higher than or equal to 29 degrees turn on first LED
  {    
    digitalWrite (ledPins[4], HIGH);//turn on fifth led
  }

 if (celsius >= 30) //If temperature is higher than or equal to 30 degrees turn on first LED
  {  
    digitalWrite (ledPins[5], HIGH);//turn on sixth led
  }
  

delay(1000);//check the temperature once every second


//Turn off al the LED's
for (int thisPin = 0; thisPin < 6; thisPin++) 
   {  
    // turn all pins off:
    digitalWrite(ledPins[thisPin], LOW);    
   }
   

}
