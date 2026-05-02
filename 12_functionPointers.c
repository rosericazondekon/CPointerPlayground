/*
 * Function Pointers in C
 * Description: Explores the concept of function pointers in C, demonstrating their usage and implications
 * Author: R. Azondekon
 * Date: 05/01/2026
 * Modified: 05/01/2026
 */

 #include <stdio.h>

 int add(int x, int y){
    return x + y;
 }

 void greet(char* name){
    printf("Hello, %s!\n", name);
 }

 int main(){
    int result;
    int (*funcptr)(int, int); // Declare a function pointer that can point to a function taking two integers as parameters and returning an integer
    funcptr = &add; // Assign the address of the add function to the function pointer
    // functptr = add; // We can also assign the function pointer to the function name without the address-of operator (&) because the function name itself represents the address of the function in C

    result = (*funcptr)(4, 5); // De-reference and executing the function pointer
    // result = funcptr(4, 5); // We can also call the function pointer without de-referencing it
    printf("The sum of 4 and 5 is: %d\n", result);

    void (*greetptr)(char*); // Declare a function pointer that can point to a function taking no parameters and returning void
    greetptr = greet; // Assign the address of the greet function to the function pointer
    greetptr("Alice"); // Call the function through the function pointer
    return 0;
 }