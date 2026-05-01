/*
 * Pointers as function arguments in C - call by reference
 * Description: Explores the concept of pointers as function arguments in C, demonstrating call by reference
 * Author: R. Azondekon
 * Date: 05/01/2026
 * Modified: 05/01/2026
 */

 #include <stdio.h>

void increment(int a){
    a++;
    printf("Address of variable in increment function: %d\n", &a); // print the address of variable a in increment function
    printf("Value of variable in increment function: %d\n", a); // print the
}

void incrementByReference(int *a){
    (*a) = (*a) + 1;
    printf("Address of variable in incrementByReference function: %d\n", a); // print the address of variable a in incrementByReference function
    printf("Value of variable in incrementByReference function: %d\n", *a); // print the value of variable a in incrementByReference function
}
 void main(){
    int a = 10;
    printf("Initial value of variable a: %d\n", a); // print the initial value of variable a

    // Call by value - passing a copy of the variable to the function
    printf("\nCall by Value:\n");
    increment(a); // call increment function with variable a (call by value)
    printf("Address of variable a in main function: %d\n", &a); // print the address of variable a in main function
    printf("Value of variable a in main function: %d\n", a); // print the value of variable a in main function (will not change because we passed a by value)

    // Call by reference - passing the address of the variable to the function
    printf("\nCall by Reference:\n");
    incrementByReference(&a); // call incrementByReference function with address of variable a (call by reference)
    printf("Address of variable a in main function: %d\n", &a); // print the address of variable a in main function
    printf("Value of variable a in main function: %d\n", a); // print the value of variable a in main function (will change because we passed a by reference)
 }