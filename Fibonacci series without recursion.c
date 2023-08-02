#include <stdio.h>

int main() {
    int num, first = 0, second = 1, next;

    printf("Enter the number of terms in the Fibonacci series: ");
    scanf("%d", &num);

    if (num < 1) {
        printf("Invalid input. Please enter a positive integer.\n");
    } else {
        printf("Fibonacci series of %d terms: ", num);

        for (int i = 0; i < num; i++) {
            if (i <= 1) {
                next = i; // For the first two terms (0 and 1)
            } else {
                next = first + second;
                first = second;
                second = next;
            }
            printf("%d ", next);
        }
        printf("\n");
    }

    return 0;
}
