#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char input[100];
    int i = 0;

    printf("Enter an expression: ");
    fgets(input, sizeof(input), stdin);

    while (input[i] != '\0') {
        if (isspace((unsigned char)input[i])) {
            i++;
            continue;
        }

        if (isalpha((unsigned char)input[i])) {
            printf("Identifier: ");
            while (isalnum((unsigned char)input[i]) || input[i] == '_') {
                printf("%c", input[i]);
                i++;
            }
            printf("\n");
        }
        else if (isdigit((unsigned char)input[i])) {
            printf("Number: ");
            while (isdigit((unsigned char)input[i])) {
                printf("%c", input[i]);
                i++;
            }
            printf("\n");
        }
        else if (strchr("+-*/=", input[i])) {
            printf("Operator: %c\n", input[i]);
            i++;
        }
        else {
            printf("Special Symbol: %c\n", input[i]);
            i++;
        }
    }

    return 0;
}
