#include <stdio.h>

int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    // Check if the number is positive, negative, or zero using goto
    if (num > 0) {
        goto positive;
    } else if (num < 0) {
        goto negative;
    } else {
        goto zero;
    }

positive:
    printf("The number is positive.\n");
    return 0;

negative:
    printf("The number is negative.\n");
    return 0;

zero:
    printf("The number is zero.\n");
    return 0;
}
