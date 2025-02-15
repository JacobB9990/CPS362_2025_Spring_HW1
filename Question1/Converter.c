#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_SIZE 256
#define BINARY_SIZE 65 // 64 + 1 for terminator


void removeNewline(char *str) {
    size_t length = strlen(str);
    if (length > 0 && str[length - 1] == '\n') {
        str[length - 1] = '\0';
    }
}

int isDecimalOrDouble(const char *str) {
    int dotCount = 0; 
    size_t length = strlen(str);

    if (length == 0) return 0; // empty string 

    for (size_t i = 0; i < length; i++) {
        if (str[i] == '.') {
            dotCount++;
            if (dotCount > 1) return 0; 
        } else if (!isdigit(str[i])) {
            return 0; // not a number
        }
    }
    
    if (length == 64 && dotCount == 0) return 2; // IEEE 754 binary

    return 1; // Valid Decimal Number
}

double convertToDouble(const char *str) {
    return strtod(str, NULL);
}

void doubleToIEEE754(double num, char *binaryStr) {
    // Treat the double as a 64-bit unsigned integer
    unsigned long long *binaryRep = (unsigned long long *)&num;

    for (int i = 63; i >= 0; i--) {
        // Extract the i-th bit by shifting and applying bitwise AND
        int bit = (*binaryRep >> i) & 1;

        binaryStr[63 - i] = bit ? '1' : '0';
    }

    binaryStr[64] = '\0';
}

void printIEEE754Breakdown(const char *binaryIEEE754) {

    char signBit = binaryIEEE754[0];

    char exponent[12];
    strncpy(exponent, binaryIEEE754 + 1, 11);
    exponent[11] = '\0';

    char mantissa[53];
    strncpy(mantissa, binaryIEEE754 + 12, 52);
    mantissa[52] = '\0';

    // Convert the Exponent from binary to decimal
    unsigned int expValue = 0;
    for (int i = 0; i < 11; i++) {
        if (exponent[i] == '1') {
            expValue |= (1 << (10 - i));
        }
    }

    int unbiasedExpValue = expValue-1023;

    printf("IEEE 754 64-bit Breakdown:\n");
    printf("Sign bit: %c \n", signBit);
    printf("Exponent: %s (Biased: %u, Unbiased: %u) \n", exponent, expValue, unbiasedExpValue);
    printf("Mantissa: 1.%s\n", mantissa); // 1 is implicit
}

int main(void) {
    char userInput[MAX_INPUT_SIZE];

    printf("Enter a 64-bit binary string or a decimal number: ");
    
    if (fgets(userInput, sizeof(userInput), stdin) == NULL) {
        printf("Error getting input\n");
        return 1;
    }

    removeNewline(userInput);

    switch (isDecimalOrDouble(userInput)) {
        case 1: // It's a Decimal Number
        {
            double result = convertToDouble(userInput);
            printf("Converted to double: %lf\n", result);
            char binaryIEEE754[BINARY_SIZE];
            doubleToIEEE754(result, binaryIEEE754);

            printf("Converted to IEEE754: %s \n", binaryIEEE754);
            printIEEE754Breakdown(binaryIEEE754);
            break;
        }
        case 2: // It's a IEEE 754 Binary
            
            break;
        default:
            printf("Not a valid decimal or binary double, please check input\n");
            break;
    }

    return 0;
}