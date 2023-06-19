# Classic Stacker Arcade Game
Introduction
The stacker game is a classic arcade game. The game initializes and displays a bar
moving at the bottom of a 8x8 LED matrix. The object of the game is to try and stack
bars all the way to the top. As you stack more and more bars, the size of the sequential
bars becomes smaller and smaller. In order to stack a bar onto the matrix, simply press
the button. For each successful grid completion, a point is awarded to the player. If your
current score surpasses that of the high score, the high score will update. The high
score and current score is displayed on the 4 digit, 7 segment display.
Complexities
My complexities are the External EEPROM that is used to store the high score when the
system is turned off, the 4 digit, 7 segment display that is used to display the high score
and the current score, and an 8x8 LED matrix that is connected to a MAX7219
multiplexer, that is used to display the game. All 3 of these complexities were
implemented successfully. However, the LED matrix connected to the MAX7219 was
not the first matrix that I tried to use for the project. Originally I was going to control the
matrix using shift registers, but I fried the matrix due to an error on my end, as I did not
put the right resistors.
User Guide
A user would interact with this system simply by pressing the button that controls the
stacking aspect of the game. The game indicates when you lost by displaying an L on
the matrix and will indicate when you have won by displaying a happy face on the
matrix. The game will update the scores on its own and will automatically restart itself.
Hardware Components
● Elegoo Uno R3 Microcontroller
● Breadboard
● Wires
● 1 button
● 1 220 Ohm Resistor
● 1 External EEPROM
● 1 4 Digit 7 Segment Display
● 8x8 LED Matrix
● MAX7129
Software Libraries Used
● Wire.h - Used to write and read from the External EEPROM
● SPI.h - Used to transmit and write data to the matrix
