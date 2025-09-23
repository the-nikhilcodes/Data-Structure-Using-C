
// This program implements a linear search algorithm in C.
#include<stdio.h>

int main() {

int array [100], search, i, n;

    printf("Enter number of elements in array: ");
    scanf("%d", &n);

    printf("Enter numbers: ");
    for(i=0; i<n; i++)
     scanf("%d", &array[i]);

    printf("Enter number to search: \n");
    scanf("%d", &search);
    for(i=0; i<n; i++)
    {
        if(array[i]==search)
        {
            printf("%d is present at location %d\n", search, i+1);
            break;
        } else {
            printf("%d is not present in the array\n");
        }
    }

}