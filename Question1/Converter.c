#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

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

double IEEE754ToDecimal(const char *binaryIEEE) {

    char signBit = binaryIEEE[0] == '1' ? -1 : 1;

    char exponent[12];
    strncpy(exponent, binaryIEEE + 1, 11);
    exponent[11] = '\0';

    char mantissa[53];
    strncpy(mantissa, binaryIEEE + 12, 52);
    mantissa[52] = '\0'; 

    unsigned int expValue = 0;
    for (int i = 0; i < 11; i++) {
        if (exponent[i] == '1') {
            expValue |= (1 << (10 - i));
        }
    }

    int actualExponent = expValue - 1023;

    double mantissaValue = 1.0; // start with implicit 1 
    for (int i = 0; i < 52; i++) {
        if (mantissa[i] == '1') {
            mantissaValue += pow(2, -(i + 1));
        }
    }

    double result = signBit * mantissaValue * pow(2, actualExponent);
    return result;
}


int main(void) {

    char userInput[MAX_INPUT_SIZE];
    char binaryIEEE754[BINARY_SIZE];
    
    printf("Enter a IEEE754 String or a decimal number: ");
    
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
            doubleToIEEE754(result, binaryIEEE754);

            printf("Converted to IEEE754: %s \n", binaryIEEE754);
            printIEEE754Breakdown(binaryIEEE754);
            break;
        }
        case 2: // It's a IEEE 754 Binary
        {
            double result = IEEE754ToDecimal(userInput);
            printf("Converted to Decimal: %lf\n", result);
            doubleToIEEE754(result, binaryIEEE754);
            printIEEE754Breakdown(binaryIEEE754);
            break;
        }
        default:
            printf("Not a valid decimal or binary double, please check input\n");
            break;
    }

    return 0;
}