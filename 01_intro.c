/*
 * What is a Pointer in C?
 * Description: Introduces the concept of pointers in C programming language
 * Author: R. Azondekon
 * Date: 05/01/2026
 * Modified: 05/01/2026
 */

#include <stdio.h>

void main(){
    int a; // declare an integer variable a
    int *p; // declare a pointer variable p that can point to an integer
    p = &a; // assign the address of a to pointer p
    a = 5; // assign value 5 to variable a
    printf("Value of a: %d\n", a); 
    printf("Address of a: %d\n", &a);
    printf("Value of p: %d\n", p);
    printf("Address of p: %d\n", &p);
    printf("Value pointed to by p: %d\n", *p); // dereference p to get value of a
    *p = 8; // change value of a through pointer p
    printf("New value of a: %d\n", a);
}