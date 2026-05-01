/*
 * Pointers and Dynamic Memory Allocation in C
 * Description: Explores the concept of pointers and dynamic memory allocation in C, demonstrating their relationship and usage
 * Author: R. Azondekon
 * Date: 05/01/2026
 * Modified: 05/01/2026
 */

 #include <stdio.h>
 #include <stdlib.h> // Include for dynamic memory allocation functions like malloc, calloc, realloc, and free

 void main(){

    // PART 1
    int a; // goes on the stack
    int *ptr;
    ptr = (int *)malloc(sizeof(int)); // reserve space allocation on the heap; ptr still goes on the stack but it points to a memory location on the heap where the integer is stored
    *ptr = 35; // assign value to the memory location pointed to by ptr
    free(ptr); // free the memory allocated on the heap to prevent memory leaks
    ptr = (int*)malloc(sizeof(int)); // we can also reassign ptr to point to a new memory location on the heap, but this may cause a memory leak if the previous memory location is not freed due to loss of reference to it
    *ptr = 45; // assign value to the new memory location pointed to by ptr
    
    // Assign value to array of integers using dynamic memory allocation
    ptr = (int*)realloc(ptr, sizeof(int) * 20); // we can also use realloc to resize the memory block pointed to by ptr
    ptr[0] = 50; // assign value to the first element in the array
    ptr[1] = 60; // assign value to the second element in the array
    ptr[2] = 70; // assign value to the third element in the array
    *(ptr + 3) = 80; // assign value to the fourth element in the array using pointer arithmetic
    *(ptr + 4) = 90; // assign value to the fifth element in the array using pointer arithmetic
    *(ptr + 5) = 100; // assign value to the sixth element in the array using pointer arithmetic
    printf("Values in the dynamically allocated array:\n");
    for(int i = 0; i < 6; i++){
        printf("ptr[%d] = %d, ", i, ptr[i]); // print the values in the dynamically allocated array using array indexing
    }
    printf("\n");
    free(ptr); // free the memory allocated on the heap to prevent memory leaks

    // Use of new and delete operators in C++ (if we were using C++)
    // int *ptr2 = new int; // allocate memory for a single integer on the heap and return a pointer to it
    // *ptr2 = 100; // assign value to the memory location pointed to by ptr2
    // delete ptr2; // free the memory allocated on the heap to prevent memory leaks

    // int *arr = new int[10]; // allocate memory for an array of 10 integers on the heap and return a pointer to the first element
    // arr[0] = 1; // assign value to the first element in the array
    // arr[1] = 2; // assign value to the second element in the array
    // delete[] arr; // free the memory allocated on the heap for the array to prevent memory leaks

    //PART 2
    int n;
    printf("\nEnter the number of elements in the array: ");
    scanf("%d", &n); // read the number of elements in the array from user
    int *dynamicArray = (int*)calloc(n, sizeof(int)); // allocate memory for an array of n integers on the heap and return a pointer to the first element

    if(dynamicArray != NULL){
        for(int i = 0; i < n; i++){
            printf("Enter element %d: ", i + 1);
            scanf("%d", &dynamicArray[i]); // read each element of the array from user and store it in the dynamically allocated array
        }
    }
    else{ printf("Dynamic Memory Allocation Failed!\n"); }

    printf("Your array is: [");
    for(int i =0; i <n; i++){
        printf("%d", dynamicArray[i]); // print the elements of the dynamically allocated array
        if(i < n - 1){
            printf(", "); // print a comma and space between elements, but not after the last element
        }
    }
    printf("]\n");

    free(dynamicArray); // free the memory allocated on the heap to prevent memory leaks
}

 