/*
 * Pointer Arithmetic in C
 * Description: Demonstrates pointer basics and pointer arithmetic in C
 * Author: R. Azondekon
 * Date: 05/01/2026
 * Modified: 05/01/2026
 */

#include <stdio.h>

void main(){
    int a; // declare an integer variable a
    int *p; // declare a pointer variable p that can point to an integer
    a = 10;
    p = &a; // assign the address of a to pointer p
    printf("Value of pointer p: %d\n", p); // print the value of pointer p (address of a)
    printf("Value pointed to by p: %d\n", *p); // print the value pointed to by p (value of a)
    printf("Address of a: %d\n", &a); // print the address of a
    *p = 20; // change the value of a through pointer p - dereferencing
    printf("New value of a: %d\n", a); // print the new value of a
    int b = 30; // declare and initialize an integer variable b
    *p = b; // assign the value of b to a through pointer p
    printf("New value of pointer p: %d\n", p); // print the value of pointer p (address of a)
    printf("New value pointed to by p: %d\n", *p); // print the value pointed to by p (value of a)
    printf("New value of a: %d\n", a); // print the value of a

    // Pointer Arithmetic
    printf("\nPointer Arithmetic:\n");
    printf("Value of pointer p: %d\n", p); // print the value of pointer p (address of a)
    printf("Value at address p is %d\n", *p); // print the value at the address pointed to by p
    printf("Size of integer: %d bytes\n", sizeof(int)); // print the size of an integer in bytes
    printf("Value of pointer (p + 1) = %d\n", p + 1); // print the value of pointer p + 1 (address of next integer)
    printf("Value at address (p + 1) is %d\n", *(p + 1)); // print the value at the address pointed to by p + 1 (undefined behavior)
    printf("Value of pointer (p + 2) = %d\n", p + 2); // print the value of pointer p + 2 (address of next integer)
    
    // Pointer Arithmetic with different data types (Try It Yourself)
    char c; // declare a char variable c
    char *cp; // declare a pointer variable cp that can point to a char
    double d; // declare a double variable d
    double *dp; // declare a pointer variable dp that can point to a double
    
}