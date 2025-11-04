#include <stdio.h>

int main() {
    int arr[100];    // Array with capacity of 100
    int n, i, pos, value;

    // Step 1: Take array size and elements
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Step 2: Display array
    printf("\nOriginal array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    // Step 3: Insertion
    printf("\n\nEnter position to insert (1 to %d): ", n + 1);
    scanf("%d", &pos);
    printf("Enter value to insert: ");
    scanf("%d", &value);

    // Shift elements to the right
    for (i = n - 1; i >= pos - 1; i--) {
        arr[i + 1] = arr[i];
    }
    arr[pos - 1] = value;
    n++;

    printf("\nArray after insertion:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    // Step 4: Deletion
    printf("\n\nEnter position to delete (1 to %d): ", n);
    scanf("%d", &pos);

    for (i = pos - 1; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;

    printf("\nArray after deletion:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    // Step 5: Searching
    printf("\n\nEnter value to search: ");
    scanf("%d", &value);

    int found = 0;
    for (i = 0; i < n; i++) {
        if (arr[i] == value) {
            printf("Element %d found at position %d.\n", value, i + 1);
            found = 1;
            break;
        }
    }

    if (!found)
