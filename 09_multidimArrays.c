/*
 * Pointers and Multidimensional Arrays in C
 * Description: Explores the concept of pointers and multidimensional arrays in C, demonstrating their relationship and usage
 * Author: R. Azondekon
 * Date: 05/01/2026
 * Modified: 05/01/2026
 */

 #include <stdio.h>

 // Define function to take a multidimensional array as an argument
void multiDFuncA(int *arr){ // OR void multiDFuncA(int arr[]) - both are equivalent since the array will decay to a pointer to its first element when passed as an argument
    printf("1-D array successfully passed to multiDFuncA function\n");
} // This function takes a pointer to an integer, which can be used to access the elements of a multidimensional array when passed as an argument

void multiDFuncB(int (*arr)[3]){ // OR void multiDFuncB(int arr[][3])
    printf("2-D array successfully passed to multiDFuncB function\n");
} // This function takes a pointer to an array of 3 integers, which can be used to access the elements of a 2D array when passed as an argument

void multiDFuncC(int (*arr)[2][2]){ // OR void multiDFuncC(int arr[][2][2])
    printf("3-D array successfully passed to multiDFuncC function\n");
} // This function takes a pointer to an array of 2 arrays of 2 integers, which can be used to access the elements of a 3D array when passed as an argument


 int main(){
    int multiArray[3][2][2] = {
        {{1, 2}, {3, 4}},
        {{5, 6}, {7, 8}},
        {{9, 10}, {11, 12}}
    }; // returns int (*)[2][2]

    printf("%d %d %d %d\n\n", multiArray, *multiArray, multiArray[0], &multiArray[0][0]); // print the value of pointer multiArray (address of first element of multiArray), the value at that address (address of first element of multiArray[0]), the value at that address (first element of multiArray[0][0]), and the address of the first element of multiArray[0][0]
    printf("Second element of multiArray[0][0] `*(multiArray[0][0] + 1)`: %d\n", *(multiArray[0][0] + 1)); // print the value of the second element of multiArray[0][0] using array indexing
    printf("Address of first element of multiArray[0][1] `*(multiArray[0] + 1)`: %d\n", *(multiArray[0] + 1)); // print the value of the first element of multiArray[0][1] using pointer arithmetic
    printf("Value of the second element of multiArray[1][0] `*(*(multiArray + 1) + 1)`: %d\n", *(*(multiArray + 1) + 1)); // print the value of the second element of multiArray[1][0] using pointer arithmetic
    printf("Value of the second element of multiArray[1][1] `*(*(*(multiArray + 1) + 1) + 1)`: %d\n", *(*(*(multiArray + 1) + 1) + 1)); // print the value of the second element of multiArray[1][1] using pointer arithmetic

    // Passing multidimensional array as a function argument
    int A[2] = {1, 2}; // returns int*
    int B[2][3] = {{1, 2, 0}, {3, 4, 9}}; // returns int (*)[3]

    // We can pass the multidimensional array multiArray to a function that expects a pointer to an array of 2 arrays of 2 integers, since the array will decay to a pointer to its first element (which is an array of 2 arrays of 2 integers)
    printf("\nPassing multidimensional arrays to functions:\n");
    multiDFuncA(A); // we can pass a 1D array to a function that expects a pointer to an integer, since the array will decay to a pointer to its first element
    multiDFuncB(B); // we can pass a 2D array to a function that expects a pointer to an array of 3 integers, since the array will decay to a pointer to its first element (which is an array of 3 integers)
    multiDFuncC(multiArray); // we can pass a 3D array to a function that expects a pointer to an array of 2 arrays of 2 integers, since the array will decay to a pointer to its first element (which is an array of 2 arrays of 2 integers)
    return 0;
}
