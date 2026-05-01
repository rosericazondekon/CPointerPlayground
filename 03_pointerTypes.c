/*
 * Pointer Types, void pointer, and pointer arithmetic in C
 * Description: Explores different pointer types in C, including void pointers and pointer arithmetic
 * Author: R. Azondekon
 * Date: 05/01/2026
 * Modified: 05/01/2026
 */

 #include <stdio.h>

 void main(){
    int a = 1025; // declare and initialize an integer variable a
    int *ip; // declare a pointer variable ip that can point to an integer
    ip = &a; // assign the address of a to pointer ip
    printf("Value of a: %d\n", a); // print the value of a
    printf("Address of a: %d\n", &a); // print the address of a
    printf("Pointer ip: %d, value at address ip: %d\n", ip, *ip); // print the value of pointer ip (address of a) and the value at that address
    printf("Size of integer: %d bytes\n", sizeof(int)); // print the size of an integer in bytes
    char *cp; // declare a pointer variable cp that can point to a char
    cp = (char *)ip; // assign the address of a to pointer cp (typecasting)
    printf("Size of char: %d bytes\n", sizeof(char)); // print the size of a char in bytes
    printf("Pointer cp: %d, value at address cp: %d\n", cp, *cp); // print the value of pointer cp (address of a) and the value at that address (first byte of a)
    // 1025 in binary is 00000000 00000000 00000100 00000001 (4 bytes)
    // The first byte (least significant byte) is 00000001 (1 in decimal)

    printf("Pointer (ip + 1): %d, value at address: %d\n", ip + 1, *(ip + 1)); // print the value of pointer ip (address of a) and the value at that address
    // ip + 1 will point to the next integer (4 bytes ahead), which is undefined behavior since we only have one integer allocated

    printf("Pointer (cp + 1): %d, value at address: %d\n", cp + 1, *(cp + 1)); // print the value of pointer cp (address of a) and the value at that address
    // cp + 1 will point to the next byte (1 byte ahead), which is 00000100 (4 in decimal)

    // Void pointer - Generic pointer that can point to any data type, but cannot be dereferenced without typecasting
    void *vp; // declare a void pointer variable vp that can point to any data type
    vp = ip; // assign the address of a to pointer vp (no typecasting needed for void pointers)
    printf("Pointer vp: %d\n", vp); // we can only print the address stored in vp, we cannot dereference it without typecasting
    // printf("Address of pointer vp + 1: %d\n", vp+1); // pointer arithmetic on void pointers is not allowed, this will cause a compilation error

    printf("Value at address of pointer vp (after typecasting to int): %d\n", *(int *)vp); // we can dereference vp after typecasting it to the correct data type (int in this case)
    printf("Value at address of pointer vp (after typecasting to char): %d\n", *(char *)vp); // we can dereference vp after typecasting it to the correct data type (char in this case)
 }