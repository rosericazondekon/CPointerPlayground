/*
 * Pointer To Pointer in C
 * Description: Explores the concept of pointers to pointers in C, including their declaration, initialization, and usage
 * Author: R. Azondekon
 * Date: 05/01/2026
 * Modified: 05/01/2026
 */

 #include <stdio.h>


 int main(){
    int a = 7; // declare and initialize an integer variable a
    int *p = &a; // declare and initialize a pointer variable p that points to a
    int **pp = &p; // declare and initialize a pointer to pointer variable pp that points to pointer p
    int ***ppp = &pp; // declare and initialize a pointer to pointer to pointer variable ppp that points to pointer pp

    printf("Value of a: %d\n", a); // print the value of a
    printf("Pointer p = %d, points to value *p: %d\n", p, *p); // print the value of pointer p (address of a) and the value at that address
    printf("Pointer pp = %d, points to pointer p: %d, value at address **pp: %d\n", pp, *pp, **pp); // print the value of pointer pp (address of p), the value at that address (address of a), and the value at that address (value of a)
    printf("Pointer ppp = %d, points to pointer pp: %d, pointer **ppp: %d, value at address ***ppp: %d\n", ppp, *ppp, **ppp, ***ppp); // print the value of pointer ppp (address of pp), the value at that address (address of p), the value at that address (address of a), and the value at that address (value of a)

    ***ppp = 10; // change the value of a through pointer to pointer to pointer ppp
    printf("New value of a (after `***ppp = 10`): %d\n", a); // print the new value of a

    **pp = *p + 5; // change the value of a through pointer to pointer pp
    printf("New value of a (after `**pp = *p + 5`): %d\n", a); // print the new value of a
    return 0;
 }