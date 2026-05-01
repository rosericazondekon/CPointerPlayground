/*
 * Character arrays as pointers in C
 * Description: Explores the concept of character arrays as pointers in C, demonstrating their relationship with pointers and usage
 * Author: R. Azondekon
 * Date: 05/01/2026
 * Modified: 05/01/2026
 */

 #include <stdio.h>
 #include <string.h>

void echoMSG(const char *ptr){
    while(*ptr != '\0'){
        printf("%c", *ptr); // print the string pointed to by ptr
        ptr++; // increment the pointer to point to the next character in the string
    }
    printf("\n");
}


 int main(){
    // PART 1
    char c[5];
    c[0] = 'P';
    c[1] = 'E';
    c[2] = 'A';
    c[3] = 'R';
    c[4] = '\0'; // null terminator to mark the end of the string
    // char c[5] = {'P', 'E', 'A', 'R', '\0'}; // we can also initialize the character array with a string literal (null terminator is automatically added)
    int len = strlen(c); // calculate the length of the string using strlen function
    printf("Character array c: %s\n", c); // print the character array c  
    printf("Size of character array c: %d bytes\n", sizeof(c)); // print the size of the character array c in bytes (including null terminator)
    printf("Length of character array c: %d\n", len); // print the length

    char d[20] = "PEAR"; // declare and initialize a character array with a string literal
    int lenD = strlen(d); // calculate the length of the string using strlen function
    printf("Size of character array d: %d bytes\n", sizeof(d)); // print the size of the character array d in bytes (including null terminator and unused space)
    printf("Length of character array d: %d\n", lenD); // print the length

    // We can also use a pointer to a character to point to the first element of the character array
    char *c2;
    c2 = c; // assign the base address of character array c to pointer c2
    printf("Pointer c2: %p, points to value c2: %s\n", (void *)c2, c2); // print the value of pointer c2 (address of first element of c) and the string it points to

    printf("First character of c2 (c2[0] or *c2): %c\n", *c2); // print the first character of the string pointed to by c2 (dereferencing the pointer to get the value of the first character)
    printf("Second character of c2 (c2[1] or *(c2 + 1)): %c\n", *(c2 + 1)); // print the second character of the string pointed to by c2 (using pointer arithmetic to access the next character)
    printf("Third character of c2 (c2[2] or *(c2 + 2)): %c\n", *(c2 + 2)); // print the third character of the string pointed to by c2 (using pointer arithmetic to access the next character)
    printf("Fourth character of c2 (c2[3] or *(c2 + 3)): %c\n", *(c2 + 3)); // print the fourth character of the string pointed to by c2 (using pointer arithmetic to access the next character)

    // c = c2; // Not valid since c2 is a pointer and c is an array name (base address), we cannot assign a pointer to an array name
    // c = c2 + 1; // Not valid since c2 is a pointer and c is an array name (base address), we cannot assign a pointer to an array name
    c2++; // we can increment the pointer c2 to point to the next character in the array
    printf("\nc2 value after incrementing pointer c2 is: %s\n", c2); // print the string pointed to by c2 after incrementing it (will print "EAR" since c2 now points to the second character of the array c)
    c2++; // we can increment the pointer c2 to point to the next character in the array
    printf("c2 value after incrementing pointer c2 again is: %s\n", c2); // print the string pointed to by c2 after incrementing it (will print "AR" since c2 now points to the third character of the array c)

    // We can also pass the character array to a function that expects a pointer to a character, since the array will decay to a pointer to its first element
    printf("\nPassing character array to custom echoMSG() function:\n");
    char msg[20] = "Hello, World!"; // declare and initialize a character array with a string literal
    echoMSG(msg); // we can pass the character array msg to a function that expects a pointer to a character (the array will decay to a pointer to its first element)

    // PART 2
    char *greetings = "Hello, World!"; // declare and initialize a pointer to a character with a string literal (string literals are stored in read-only memory and cannot be modified)
    // greetings[0] = 'h'; // this will cause a segmentation fault because we are trying to modify a string literal, which is stored in read-only memory
    // printf("\n%s\n", greetings); // print the string pointed to by greetings
    echoMSG(greetings); // we can also pass the pointer to a character that points to a string literal to the echoMSG function
    return 0;
}