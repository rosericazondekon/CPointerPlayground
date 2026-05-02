/*
 * Function pointers and callbacks in C
 * Description: Explores function pointers and callback mechanisms in C
 * Author: R. Azondekon
 * Date: 05/01/2026
 * Modified: 05/01/2026
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include <math.h> // Include for the abs function used in compareABS

 void greet(){
    printf("Greetings, my people!\n");
}

void simpleBubbleSort(int *arr, int size){
    int i, j, temp;
    for(i = 0; i<size; i++){
        for(j = 0; j < size - 1; j++){
            if(arr[j] > arr[j + 1]){ // Compare and swap if necessary
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void callback(void (*funcptr)()){
    funcptr(); // Call the function through the function pointer
}

// Comparison callback functions for Bubble sorting
int compareASC(int a, int b){
    return a - b; // Return a positive value if a > b, negative if a < b, and 0 if they are equal
}

int compareDESC(int a, int b){
    return b - a; // Return a positive value if b > a, negative if b < a, and 0 if they are equal
}

int compareABS(int a, int b){
    return abs(a) - abs(b); // Compare the absolute values of a and b
}

// Comparison callback functions for Quick sorting
// qsort required comparison functions to take const void* parameters and return an int, so we need to cast the 
// pointers to the appropriate type and dereference them to get the actual values for comparison
int qcompareASC(const void *a, const void *b){
    return (*(int*)a) - (*(int*)b); // Return a positive value if a > b, negative if a < b, and 0 if they are equal
}

int qcompareDESC(const void *a, const void *b){
    return (*(int*)b) - (*(int*)a); // Return a positive value if b > a, negative if b < a, and 0 if they are equal
}

int qcompareABS(const void *a, const void *b){
    return abs(*(int*)a) - abs(*(int*)b); // Compare the absolute values of a and b
}

// Flexible implementation of bubble sort that takes a function pointer for comparison
void bubbleSort(int *arr, int size, int (*compare)(int, int)){
    int i, j, temp;
    for(i = 0; i<size; i++){
        for(j = 0; j < size - 1; j++){
            if(compare(arr[j], arr[j + 1]) > 0){ // Compare and swap if necessary
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main(){
    // PART 1: Function pointer as a callback
    void (*greetptr)() = greet;
    callback(greetptr); // Pass the function pointer as an argument to the callback function
    
    // PART 2: Practical use case - Sorting an array using a function pointer for the sorting algorithm
    int arr[] = {-23, 3, 45, 6, 12, -5};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Sort with a simple implementation of bubble sort
    simpleBubbleSort(arr, size);
    printf("Sorted array: ");
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Sort with a more flexible implementation of bubble sort that takes a function pointer for comparison
    // Sort in ascending order
    bubbleSort(arr, size, compareASC);
    printf("\nSorted array in ascending order: ");
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Sort in descending order
    bubbleSort(arr, size, compareDESC);
    printf("Sorted array in descending order: ");
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Sort by absolute value
    bubbleSort(arr, size, compareABS);
    printf("Sorted array by absolute value: ");
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    // PART 3: Practical use case - Using qSort from the C standard library with a custom comparison function
    qsort(arr, size, sizeof(int), qcompareASC); // Sort in ascending order using qsort
    printf("\nSorted array in ascending order using qsort: ");
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    qsort(arr, size, sizeof(int), qcompareDESC); // Sort in descending order using qsort
    printf("Sorted array in descending order using qsort: ");
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    qsort(arr, size, sizeof(int), qcompareABS); // Sort by absolute value using qsort
    printf("Sorted array by absolute value using qsort: ");
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}