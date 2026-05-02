/*
 * Pointers as function returns in C
 * Description: Explores the concept of pointers as function returns in C, demonstrating their usage and implications
 * Author: R. Azondekon
 * Date: 05/01/2026
 * Modified: 05/01/2026
 */

 #include <stdio.h>
 #include <stdlib.h>

void msg(){
    printf("Hello, World!\n");
}

 int add(int x, int y){ // Called function
    // x and y are integer variables that are passed by value to the function, meaning that they are copied and any changes made to them within the function do not affect the original variables outside the function
    int z = x + y;
    return z;
 }

 int *addByReference(int *x, int *y){ // Called function
    // x and y are pointers to integer variables that are passed by reference to the function, meaning that they point to the original variables outside the function and any changes made to them within the function will affect the original variables
    // int z = *x + *y; // z is a local variable that is created on the stack and will be destroyed once the function exits, so returning a pointer to it would lead to undefined behavior.
    // return &z; // This is a common mistake in C programming, as it returns the address of a local variable (z) that goes out of scope once the function exits, leading to undefined behavior when the caller tries to access the returned pointer. 
                //To fix this issue, we can dynamically allocate memory for z on the heap and return a pointer to that memory instead.
    
    // Best practice is to avoid returning pointers to local variables and instead use dynamic memory allocation 
    // to ensure that the memory remains valid after the function exits. This way, the caller can safely access 
    // the returned pointer without risking undefined behavior.
    int* z = (int*)malloc(sizeof(int)); // Dynamically allocate memory for z on the heap
    *z = *x + *y; // Assign the sum of the values pointed to
    return z; // Return a pointer to the dynamically allocated memory
 }

 int main(){ // Calling function
    int a = 5, b = 11;

    // Call by value
    printf("Call by value\n");
    int c = add(a, b); 
    printf("The sum of %d and %d is: %d\n", a, b, c);

    // Call by reference using pointers
    printf("\nCall by reference\n");
    int *d = addByReference(&a, &b);
    msg();
    printf("The sum of %d and %d is: %d\n", a, b, *d);
    return 0;
 }