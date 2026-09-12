#include <stdio.h>

int main() {
    int arr[100], n, i;
    int max, min, sum = 0;
    float average;

    printf("Enter size of array: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    max = min = arr[0];

    for(i = 0; i < n; i++) {
        if(arr[i] > max)
            max = arr[i];

        if(arr[i] < min)
            min = arr[i];

        sum = sum + arr[i];
    }

    average = (float)sum / n;

    printf("Maximum = %d\n", max);
    printf("Minimum = %d\n", min);
    printf("Sum = %d\n", sum);
    printf("Average = %.2f\n", average);

    return 0;
}