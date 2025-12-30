#include <stdio.h>
#include <limits.h>

// Function to convert string to unsigned integer
// Returns 1 on success, 0 on failure
int stringToUnsignedInt(const char *str, unsigned int *result) {
    unsigned int num = 0;
    int i = 0;

    // Skip leading whitespace
    while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n') {
        i++;
    }

    // Check for empty string
    if (str[i] == '\0') {
        printf("Error: Empty string or only whitespace\n");
        return 0;
    }

    // Process each character
    while (str[i] != '\0' && str[i] != '\n') {
        // Check if character is a digit
        if (str[i] < '0' || str[i] > '9') {
            printf("Error: Invalid character '%c' found at position %d\n", str[i], i);
            return 0;
        }

        int digit = str[i] - '0';  // Convert char to digit

        // Check for overflow before multiplication
        if (num > UINT_MAX / 10) {
            printf("Error: Number too large (overflow)\n");
            return 0;
        }

        num = num * 10;

        // Check for overflow before addition
        if (num > UINT_MAX - digit) {
            printf("Error: Number too large (overflow)\n");
            return 0;
        }

        num = num + digit;
        i++;
    }

    *result = num;
    return 1;
}

int main() {
    char input[100];
    unsigned int number;

    printf("=== String to Unsigned Integer Converter ===\n");
    printf("Enter a string containing a positive number: ");

    // Read input from keyboard
    if (fgets(input, sizeof(input), stdin) == NULL) {
        printf("Error reading input\n");
        return 1;
    }

    // Convert string to unsigned integer
    if (stringToUnsignedInt(input, &number)) {
        printf("\nConversion successful!\n");
        printf("Result: %u\n", number);
        printf("In hexadecimal: 0x%X\n", number);
    } else {
        printf("\nConversion failed!\n");
        return 1;
    }

    return 0;
}