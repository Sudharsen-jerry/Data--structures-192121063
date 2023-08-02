#include <stdio.h>

int main() {
    int num;
    printf("Enter the number of elements: ");
    scanf("%d", &num);

    int arr[num];
    printf("Enter %d elements:\n", num);
    for (int i = 0; i < num; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Even numbers: ");
    for (int i = 0; i < num; i++) {
        if (arr[i] % 2 == 0) {
            printf("%d ", arr[i]);
        }
    }

    printf("\nOdd numbers: ");
    for (int i = 0; i < num; i++) {
        if (arr[i] % 2 != 0) {
            printf("%d ", arr[i]);
        }
    }

    printf("\n");
    return 0;
}
