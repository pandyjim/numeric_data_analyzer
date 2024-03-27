#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define SIZE 10

bool isEven(int num) {
    return num % 2 == 0;
}

bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int numbers[SIZE];
    int sum = 0;
    int max = INT_MIN;
    int min = INT_MAX;

    // Input numbers into the array
    printf("Enter %d integers:\n", SIZE);
    for (int i = 0; i < SIZE; i++) {
        if (scanf("%d", &numbers[i]) != 1) {
            printf("Invalid input. Please enter integers only.\n");
            return 1;
        }
        sum += numbers[i];
        if (numbers[i] > max) {
            max = numbers[i];
        }
        if (numbers[i] < min) {
            min = numbers[i];
        }
    }

    // Display the numbers along with their properties
    printf("\n%3s %8s %8s %8s %8s\n", "Sr.", "Number", "Prime", "Odd/Even", "Min/Max");
    for (int i = 0; i < SIZE; i++) {
        printf("%3d %8d %8s %8s %8s\n", i + 1, numbers[i], isPrime(numbers[i]) ? "Yes" : "No",
               isEven(numbers[i]) ? "Even" : "Odd", numbers[i] == max ? "Max" : (numbers[i] == min ? "Min" : ""));
    }

    // Display sum and average
    printf("\nSum: %d\n", sum);
    printf("Average: %.2f\n", (float)sum / SIZE);

    return 0;
}

