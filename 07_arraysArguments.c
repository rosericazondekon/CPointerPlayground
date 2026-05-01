/*
 * Arrays as Function Arguments in C
 * Description: Explores the concept of arrays as function arguments in C, demonstrating their relationship with pointers and usage
 * Author: R. Azondekon
 * Date: 05/01/2026
 * Modified: 05/01/2026
 */

#include <stdio.h>

int sumOfArray(int arr[], int size){
    int i, sum = 0;
    for(i = 0; i < size; i++){
        sum += arr[i]; // we can access array elements using array indexing notation
    }
    return sum;
}

int sumOfArrayPointer(int *arr, int size){
    int i, sum = 0;
    for(i = 0; i < size; i++){
        sum += *(arr + i); // we can also access array elements using pointer arithmetic notation
    }
    return sum;
}

void doubleArray(int *arr, int size){
    for(int i = 0; i < size; i++){
        arr[i] *= 2; // we can modify array elements through the pointer received as a function argument
    }
}

void main(){
    int A[] = {1, 2, 3, 4, 5}; // declare and initialize an array of integers
    int size = sizeof(A) / sizeof(int); // calculate the number of elements in the array
    
    // We can pass the array A to the sumOfArray function, which will receive it as a pointer to the first element of the array
    int total = sumOfArray(A, size); // call the sumOfArray function with array A as an argument
    printf("Sum of elements in array A: %d\n", total); // print the sum of elements in array A

    // We can also call the sumOfArrayPointer function with array A as an argument, which will receive it as a pointer to the first element of the array
    int totalPointer = sumOfArrayPointer(A, size); // call the sumOfArrayPointer function with array A as an argument
    printf("Sum of elements in array A using pointer notation: %d\n", totalPointer); // print the sum of elements in array A using pointer notation

    // We can also modify the elements of array A through a function that receives a pointer to the first element of the array
    doubleArray(A, size); // call the doubleArray function to modify the elements of array A
    printf("Array A after doubling its elements (Call by Reference):\n");
    for(int i = 0; i < size; i++){
        printf("%d ", A[i]); // print the modified elements of array A
    }
}