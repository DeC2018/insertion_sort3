/* C Program to sort an array in ascending order using Insertion Sort
* using separate function and keeping memory safety
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Simple function for printing the array in a nice way
void printarray(int ar[], const char *name, unsigned int size)
{
    printf("%s[] = [", name);
    for (unsigned int i = 0; i < size; i++)
        printf(" %d", ar[i]);
    puts(" ]\n");
}

int *throwel(int *ar, unsigned int in)
{
    unsigned int ptr = in - 1;
    while (in > 0 && ar[in] < ar[ptr]) {
        // Verbose output for showing what comparisions are being done
        printf("%d < %d\n", ar[in], ar[ptr]);
        int t = ar[in];
        ar[in--] = ar[ptr];
        ar[ptr--] = t;
    }
    return ar;
}

int *iterel(int *ar, unsigned int size)
{
    for (unsigned int i = 0; i < size - 1; i++)
    {
        if (ar[i] > ar[i + 1])
        {
            // Tell where the pointer is at and send the array and the pointer
            // index to throwel and receive it later
            printf("Pointer : ar[%d] = %d\n", i + 1, ar[i + 1]);
            memcpy(ar, throwel(ar, i + 1), size * sizeof(int));
            printarray(ar, "ar", size);
        }
    }
    return ar;
}

int main(void)
{
    puts("Enter the size of the array : ");
    unsigned int n = 10;
    scanf("%d", &n);
    int *array_to_sort = malloc(n * sizeof(int));
    puts("Enter the Array elements:\n");
    for (unsigned int i = 0; i < n; i++)
    {
        printf("array_to_sort[%d] : ", i);
        scanf("%d", &array_to_sort[i]);
    }
    // Print the array before sorting
    printarray(array_to_sort, "array_to_sort", n);
    int *result_array = iterel(array_to_sort, n);
    printarray(result_array, "result_array", n);
}
