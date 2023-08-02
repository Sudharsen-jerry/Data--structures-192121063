#include <stdio.h>

int fibonacci(int n) {
    if (n == 0) {
        return 0; // Base case: Fibonacci of 0 is 0
    } else if (n == 1) {
        return 1; // Base case: Fibonacci of 1 is 1
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2); // Recursive call to calculate Fibonacci
    }
}

int main() {
    int num;
    printf("Enter the number of terms in the Fibonacci series: ");
    scanf("%d", &num);

    if (num < 1) {
        printf("Invalid input. Please enter a positive integer.\n");
    } else {
        printf("Fibonacci series of %d terms: ", num);
        for (int i = 0; i < num; i++) {
            printf("%d ", fibonacci(i));
        }
        printf("\n");
    }

    return 0;
}
