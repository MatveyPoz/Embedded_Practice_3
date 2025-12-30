# Practice 3 (Variant 18)
####  A C application that converts a string to an unsigned integer without using library conversion functions like ` atoi() ` or ` strtoul()`
Converts each character digit to its numeric value without using `atoi()`, `strtoul()` etc.

Error handling:
- Detects non-numeric characters 
- Checks for overflow (numbers larger than UINT_MAX)
- Handles empty strings and whitespace


Algorithm: Multiplies the current result by 10 and adds the new digit for each character

How it works:

Reads a string from the keyboard using fgets()
Skips leading whitespace

Processes each character:
1. Verifies it's a digit ('0'-'9')
2. Converts character to digit by subtracting '0' 
3. Multiplies running total by 10 and adds the digit 
4. Checks for overflow at each step


Displays the result in decimal and hexadecimal

