### 1. (50 pts) Bi-directional Decimal-Double Converter

Write a bi-directional decimal-double converter. Given a decimal, the program converts it to the double, and given a double, it converts it to the decimal. IEEE 754 must be followed. In addition to the converted values, the program is required to print out the sign bit, the unbiased exponent, and the mantissa, in binary, for every input. C is highly recommended. High-level programming languages such as Python and Java are NOT recommended. (Hint: Use `-00 -g3 -Ma11` if you use `gcc`.)

### Answer

The program takes an input, checks if its a Decimal or IEEE 754 Binary number by going through each charecter and checking if its a digit or a period and if its a 64 length number with no periods its considered a IEEE Number.

#### Decimal to IEEE

If the input is a decimal number, the program first converts it into a double . Then, it reinterprets the bits of the double as a 64-bit unsigned integer. The program extracts the bits starting from the Most Significant Bit (MSB) to the Least Significant Bit (LSB), basically converting it into its IEEE 754 binary format. After extracting and organizing the bits, it formats and prints the output in a human readable way.

#### IEEE To Decimal

If the input is an IEEE 754 binary string (64-bit), the program first extracts the sign bit, exponent, and mantissa from the binary string. The exponent is decoded by subtracting the bias of 1023 from its value. The mantissa is interpreted by adding an implicit leading 1 to the fraction and then converting the binary fraction into its decimal equivalent. Finally, the program calculates the decimal value using the formula:

$$ \text{Decimal Value} = (-1)^{\text{sign}} \times \text{mantissa} \times 2^{\text{exponent} - 1023} $$

This decimal value is then printed along with the readable IEEE 754 binary.

#### Sample Outputs

##### Example-1:

Enter a 64-bit binary string or a decimal number: 1.233
Converted to double: 1.233000
Converted to IEEE754: 0011111111110011101110100101111000110101001111110111110011101110
IEEE 754 64-bit Breakdown:
Sign bit: 0
Exponent: 01111111111 (Biased: 1023, Unbiased: 0)
Mantissa: 1.0011101110100101111000110101001111110111110011101110

###### Example-2:

Enter a 64-bit binary string or a decimal number: 0011111111110011101011100001010001111010111000010100011110101110
Converted to double: 1.230000
IEEE 754 64-bit Breakdown:
Sign bit: 0
Exponent: 01111111111 (Biased: 1023, Unbiased: 0)
Mantissa: 1.0011101011100001010001111010111000010100011110101110
