/*
 * Pointers and Arrays in C
 * Description: Explores the concept of pointers and arrays in C, demonstrating their relationship and usage
 * Author: R. Azondekon
 * Date: 05/01/2026
 * Modified: 05/01/2026
 */

 #include <stdio.h>

 void main(){
    int A[] = {1, 2, 3, 4, 5}; // declare and initialize an array of integers
    int *p = A; // declare a pointer to an integer and initialize it with the base address of array A
    // A++; // this will cause a compilation error because we cannot change the base address of an array
    // p++; // we can increment the pointer p to point to the next element in the array
    printf("Address of Array A: %d\n", A); // print the base address of array A (which is the address of the first element)
    printf("Adress of first element A[0]: %d\n", &A[0]); // print the address of the first element of array A
    printf("Value of first element A[0]: %d\n", A[0]); // print the value of the first element of array A
    printf("Value of first element using pointer notation `*A`: %d\n", *A); // print the value of the first element of array A using pointer notation (dereferencing the base address)

    // Array indexing and pointer arithmetic
    printf("\nArray Indexing:\n");
    for(int i=0; i < 5; i++){
        printf("Address of A[%d]: %d, Value: %d\n", i, &A[i], A[i]); // print the address and value of each element in array A using array indexing
    }

    // We can also use pointer arithmetic to access array elements
    printf("\nArray indexing using Pointer Arithmetic:\n");
    for(int i=0; i < 5; i++){
        printf("Address of A[%d] using pointer arithmetic `A+i` : %d, Value *(A+i): %d\n", i, A + i, *(A + i)); // print the address and value of each element in array A using pointer arithmetic
    }
 }