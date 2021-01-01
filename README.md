# Serial-to-LCD
Arduino code for displaying text from the serial port onto a 16*2 character LCD

## Libraries Used
The Liquid Crystal i^2C library by fdebrabander and João Pedro São Gregorio Silva is used.  
Link: https://github.com/fdebrabander/Arduino-LiquidCrystal-I2C-library  

## Description  
The program takes strings from the serial input and displays them in the most convenient way on the LCD. The '^' symbol can be used to manually set the text onto the next display line. 

The code follows this flowchart:  
  
<img src="https://github.com/Linja82/Serial-to-LCD/blob/main/Screenshots/String%20Convertor%20Flowchart.jpg" alt ="alt text" width="550" height="417">  

## Examples  
Input: "It is currently^10:00 AM"  
Output:  
<img src="https://github.com/Linja82/Serial-to-LCD/blob/main/Screenshots/Example%201.jpg" alt="alt text" width="345" height="113">  
  
Input: "What time is it right now?"  
Output:  
<img src="https://github.com/Linja82/Serial-to-LCD/blob/main/Screenshots/Example%202.jpg" alt="alt text" width="345" height="113">
