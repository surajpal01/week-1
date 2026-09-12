#include <stdio.h>

int main() {
    int arr[100], n, key, i;
    int linear = -1, binary = -1;
    int low, high, mid;

    printf("Enter size of array: ");
    scanf("%d", &n);

    printf("Enter sorted array elements:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter element to search: ");
    scanf("%d", &key);

    // Linear Search
    for(i = 0; i < n; i++) {
        if(arr[i] == key) {
            linear = i;
            break;
        }
    }

    // Binary Search
    low = 0;
    high = n - 1;

    while(low <= high) {
        mid = (low + high) / 2;

        if(arr[mid] == key) {
            binary = mid;
            break;
        }
        else if(arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    if(linear != -1)
        printf("Linear Search: Element found at position %d\n", linear + 1);
    else
        printf("Linear Search: Element not found\n");

    if(binary != -1)
        printf("Binary Search: Element found at position %d\n", binary + 1);
    else
        printf("Binary Search: Element not found\n");

    return 0;
}