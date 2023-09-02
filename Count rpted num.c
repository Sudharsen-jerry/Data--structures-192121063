 #include <stdio.h>

#define MAX_SIZE 1000 

void printFrequentNumbersCount(int arr[], int size, int k) {
    int count[MAX_SIZE] = {0}; 

    for (int i = 0; i < size; i++) {
        count[arr[i]]++;
    }

    printf("Frequently repeated numbers with count >= %d:\n", k);

    for (int i = 0; i < MAX_SIZE; i++) {
        if (count[i] >= k) {
            printf("%d (count: %d)\n", i, count[i]);
        }
    }
}

int main() {
    int arr[] = {1, 2, 2, 3, 4, 4, 4, 5, 5, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int k = 2; 

    printFrequentNumbersCount(arr, size, k);

    return 0;
}
