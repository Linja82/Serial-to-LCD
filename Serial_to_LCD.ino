/* Arduino Calendar V1.2
 * @author Linja
 * @date December 24, 2020
 * 
 * Display messages from the serial input on a 2 line LCD
 * 
 * Note: Potentiometer on the 4-pin lcd adapter is for adjusting contrast
 * Wiring: SCL -> Analog pin 5
 * Wiring: SDA -> Analog pin 4
 * Command for backlight off = (lcd.noBacklight();)
 * Command for backlight on = (lcd.backlight();)
 * 
 * Note:
 * '^' is the symbol used to symbolize switching to the next line on the display
 */

#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
String completeText;

void setup() {
  Serial.begin(9600);
  lcd.begin();
  lcd.backlight();
  lcd.setCursor(0, 0);
  Serial.print("Ready\n");
}

void loop() {
  if(Serial.available())                          // If there is an input on the serial lines
  {
    lcd.clear();
    completeText = Serial.readStringUntil('\n');
    if(completeText.indexOf('^') != -1)           // If there is a line split symbol
    {
      String partOne,partTwo;
      int splitLocation = completeText.indexOf('^');
      partOne = completeText.substring(0, splitLocation);
      partTwo = completeText.substring(splitLocation + 1, completeText.length());

      // For Testing
      Serial.print(partOne + '\n');
      Serial.print(partTwo + '\n');

      lcd.print(partOne);
      lcd.setCursor(0, 1);
      lcd.print(partTwo);
    }
    else                                          // If there is not a line split symbol
    {
      if(isTooLong(completeText))                 // If the string input is longer than 16 characters
      {
        int splitPoint = spaceBeforeSixteen(completeText);
        String partOne, partTwo;
        partOne = completeText.substring(0, splitPoint);
        partTwo = completeText.substring(splitPoint, completeText.length());

        lcd.print(partOne);
        lcd.setCursor(0, 1);
        lcd.print(partTwo);
        
        Serial.print(partOne + '\n' + partTwo + '\n');
      }
      else                                        // If the string input is shorter than or equal to 16 characters
      {
        lcd.print(completeText);
        Serial.print(completeText + '\n');
      }
    }
    lcd.setCursor(0, 0);
  }
}

bool isTooLong(String textCheck)
{
  return(textCheck.length() > 16);  
}

int spaceBeforeSixteen(String textCheck)
{
  String partOne = completeText.substring(0, 15);
  String partOneReverse = reverse(partOne);
  if (completeText.indexOf(' ') != -1)            // If there is a space before 16 characters
  {
    int spaceLocation = partOneReverse.indexOf(' ');
    spaceLocation = partOne.length() - spaceLocation;
    return spaceLocation;
  }
  else                                            // If there is no space before 16 characters
  {
    return -1;
  }
}

String reverse(String text)
{
  String reverseText;
  for(int i = 0; i < text.length(); i++)                     // Reverses the text
  {
    reverseText += text.substring(text.length()- i - 1, text.length()- i); // Reverse of original text
  }
  return reverseText;
}
