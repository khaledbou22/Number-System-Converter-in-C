#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//  convert binary to decimal
int binaryToDecimal(const char *binary) {
    int decimal = 0, base = 1;
    int length = strlen(binary);
    for (int i = length - 1; i >= 0; i--) {
        if (binary[i] == '1') {
            decimal += base;
        } else if (binary[i] != '0') {
            printf("Invalid binary number!\n");
            exit(1);
        }
        base *= 2;
    }
    return decimal;
}

//  convert octal to decimal
int octalToDecimal(const char *octal) {
    int decimal = 0, base = 1;
    int length = strlen(octal);
    for (int i = length - 1; i >= 0; i--) {
        if (octal[i] >= '0' && octal[i] <= '7') {
            decimal += (octal[i] - '0') * base;
        } else {
            printf("Invalid octal number!\n");
            exit(1);
        }
        base *= 8;
    }
    return decimal;
}

//  convert hexadecimal to decimal
int hexToDecimal(const char *hex) {
    int decimal = 0, base = 1;
    int length = strlen(hex);
    for (int i = length - 1; i >= 0; i--) {
        if (hex[i] >= '0' && hex[i] <= '9') {
            decimal += (hex[i] - '0') * base;
        } else if (hex[i] >= 'A' && hex[i] <= 'F') {
            decimal += (hex[i] - 'A' + 10) * base;
        } else if (hex[i] >= 'a' && hex[i] <= 'f') {
            decimal += (hex[i] - 'a' + 10) * base;
        } else {
            printf("Invalid hexadecimal number!\n");
            exit(1);
        }
        base *= 16;
    }
    return decimal;
}
char *octalToBinary(const char *octal) {
    static char binary[128];
    binary[0] = '\0'; // تفريغ السلسلة
    char *lookup[8] = {"000", "001", "010", "011", "100", "101", "110", "111"};

    for (int i = 0; octal[i] != '\0'; i++) {
        if (octal[i] >= '0' && octal[i] <= '7') {
            strcat(binary, lookup[octal[i] - '0']);
        } else {
            printf("Invalid octal number!\n");
            exit(1);
        }
    }
    return binary;
}

//  convert decimal to binary
char *decimalToBinary(int decimal) {
    static char binary[33];
    int index = 0;
    while (decimal > 0) {
        binary[index++] = (decimal % 2) + '0';
        decimal /= 2;
    }
    binary[index] = '\0';

    for (int i = 0; i < index / 2; i++) {
        char temp = binary[i];
        binary[i] = binary[index - 1 - i];
        binary[index - 1 - i] = temp;
    }
    return binary;
}

//  convert decimal to octal
char *decimalToOctal(int decimal) {
    static char octal[32];
    int index = 0;
    while (decimal > 0) {
        octal[index++] = (decimal % 8) + '0';
        decimal /= 8;
    }
    octal[index] = '\0';
    for (int i = 0; i < index / 2; i++) {
        char temp = octal[i];
        octal[i] = octal[index - 1 - i];
        octal[index - 1 - i] = temp;
    }
    return octal;
}

//  convert decimal to hexadecimal
char *decimalToHex(int decimal) {
    static char hex[32];
    int index = 0;
    while (decimal > 0) {
        int remainder = decimal % 16;
        if (remainder < 10) {
            hex[index++] = remainder + '0';
        } else {
            hex[index++] = remainder - 10 + 'A';
        }
        decimal /= 16;
    }
    hex[index] = '\0';


    for (int i = 0; i < index / 2; i++) {
        char temp = hex[i];
        hex[i] = hex[index - 1 - i];
        hex[index - 1 - i] = temp;
    }
    return hex;
}
// convert hexadecimal to binary
char *hexToBinary(const char *hex) {
    static char binary[129] = "";  
    binary[0] = '\0';             

    for (int i = 0; hex[i] != '\0'; i++) {
        switch (hex[i]) {
            case '0': strcat(binary, "0000"); break;
            case '1': strcat(binary, "0001"); break;
            case '2': strcat(binary, "0010"); break;
            case '3': strcat(binary, "0011"); break;
            case '4': strcat(binary, "0100"); break;
            case '5': strcat(binary, "0101"); break;
            case '6': strcat(binary, "0110"); break;
            case '7': strcat(binary, "0111"); break;
            case '8': strcat(binary, "1000"); break;
            case '9': strcat(binary, "1001"); break;
            case 'A': case 'a': strcat(binary, "1010"); break;
            case 'B': case 'b': strcat(binary, "1011"); break;
            case 'C': case 'c': strcat(binary, "1100"); break;
            case 'D': case 'd': strcat(binary, "1101"); break;
            case 'E': case 'e': strcat(binary, "1110"); break;
            case 'F': case 'f': strcat(binary, "1111"); break;
            default: 
                printf("Invalid hexadecimal digit: %c\n", hex[i]);
                exit(1);
        }
    }
    return binary;
}

//  convert binary to octal
char *binaryToOctal(const char *binary) {
    int decimal = binaryToDecimal(binary);
    return decimalToOctal(decimal);
}

//  convert binary to hexadecimal
char *binaryToHex(const char *binary) {
    int decimal = binaryToDecimal(binary);
    return decimalToHex(decimal);
}

//  convert octal to hexadecimal
char *octalToHex(const char *octal) {
    int decimal = octalToDecimal(octal);
    return decimalToHex(decimal);
}


//  convert hexadecimal to octal
char *hexToOctal(const char *hex) {
    int decimal = hexToDecimal(hex);
    return decimalToOctal(decimal);
}


int main() {
    int choice;
    char input[33];

    while (1) {
        printf("\n Menu:\n");
        printf("1. Binary to Decimal\n");
        printf("2. Octal to Decimal\n");
        printf("3. Hexadecimal to Decimal\n");
        printf("4. Decimal to Binary\n");
        printf("5. Decimal to Octal\n");
        printf("6. Decimal to Hexadecimal\n");
        printf("7. Binary to Octal\n");
        printf("8. Binary to Hexadecimal\n");
        printf("9. Octal to Binary\n");
        printf("10. Octal to Hexadecimal\n");
        printf("11. Hexadecimal to Binary\n");
        printf("12. Hexadecimal to Octal\n");
        printf("13. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a binary number: ");
                scanf("%s", input);
                printf("Decimal: %d\n", binaryToDecimal(input));
                break;

            case 2:
                printf("Enter an octal number: ");
                scanf("%s", input);
                printf("Decimal: %d\n", octalToDecimal(input));
                break;

            case 3:
                printf("Enter a hexadecimal number: ");
                scanf("%s", input);
                printf("Decimal: %d\n", hexToDecimal(input));
                break;

            case 4:
                printf("Enter a decimal number: ");
                int decimal;
                scanf("%d", &decimal);
                printf("Binary: %s\n", decimalToBinary(decimal));
                break;

            case 5:
                printf("Enter a decimal number: ");
                scanf("%d", &decimal);
                printf("Octal: %s\n", decimalToOctal(decimal));
                break;

            case 6:
                printf("Enter a decimal number: ");
                scanf("%d", &decimal);
                printf("Hexadecimal: %s\n", decimalToHex(decimal));
                break;

            case 7:
                printf("Enter a binary number: ");
                scanf("%s", input);
                printf("Octal: %s\n", binaryToOctal(input));
                break;

            case 8:
                printf("Enter a binary number: ");
                scanf("%s", input);
                printf("Hexadecimal: %s\n", binaryToHex(input));
                break;

            case 9:
                printf("Enter an octal number: ");
                scanf("%s", input);
                printf("Binary: %s\n", octalToBinary(input));
                break;

            case 10:
                printf("Enter an octal number: ");
                scanf("%s", input);
                printf("Hexadecimal: %s\n", octalToHex(input));
                break;

            case 11:
                printf("Enter a hexadecimal number: ");
                scanf("%s", input);
                printf("Binary: %s\n", hexToBinary(input));
                break;

            case 12:
                printf("Enter a hexadecimal number: ");
                scanf("%s", input);
                printf("Octal: %s\n", hexToOctal(input));
                break;

            case 13:
                printf("Exiting the program , Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
