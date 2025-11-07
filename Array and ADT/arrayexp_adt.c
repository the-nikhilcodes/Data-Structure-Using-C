#include <stdio.h>

struct Array {
    int A[100];   // static array
    int size;     // total size
    int length;   // current number of elements
};

// Display elements
void display(struct Array arr) {
    printf("Array elements: ");
    for (int i = 0; i < arr.length; i++) {
        printf("%d ", arr.A[i]);
    }
    printf("\n");
}

// Insert element at index
void insert(struct Array *arr, int index, int value) {
    if (index < 0 || index > arr->length) {
        printf("Invalid index!\n");
        return;
    }
    if (arr->length == arr->size) {
        printf("Array is full!\n");
        return;
    }

    for (int i = arr->length; i > index; i--) {
        arr->A[i] = arr->A[i - 1];
    }
    arr->A[index] = value;
    arr->length++;
}

// Delete element at index
int delete(struct Array *arr, int index) {
    if (index < 0 || index >= arr->length) {
        printf("Invalid index!\n");
        return -1;
    }

    int deleted = arr->A[index];
    for (int i = index; i < arr->length - 1; i++) {
        arr->A[i] = arr->A[i + 1];
    }
    arr->length--;

    return deleted;
}

// Search (Linear Search)
int search(struct Array arr, int key) {
    for (int i = 0; i < arr.length; i++) {
        if (arr.A[i] == key)
            return i;
    }
    return -1;
}

int main() {
    struct Array arr = {{1, 2, 3, 4, 5}, 100, 5};

    display(arr);

    printf("\nInserting 10 at index 2...\n");
    insert(&arr, 2, 10);
    display(arr);

    printf("\nDeleting element at index 3...\n");
    int deleted = delete(&arr, 3);
    printf("Deleted: %d\n", deleted);
    display(arr);

    printf("\nSearching for 10...\n");
    int index = search(arr, 10);
    if (index != -1)
        printf("Found at index %d\n", index);
    else
        printf("Not found\n");

    return 0;
}
