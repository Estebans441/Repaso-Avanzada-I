#include <iostream>

using namespace std;

int main(){
    // Forma de liberar memoria asignada dinamicamente para un arreglo en C++
    // a. delete
    int *arr = new int[5];
    delete arr;

    int * num = new int(5);
    delete num;

    // b. free(arr)
    int *arr2 = (int *)malloc(5 * sizeof(int)); // es para C
    free(arr2); // es para C

    // c. delete arr[]
    // int *arr3 = new int[5];
    // delete arr3[];

    // d. delete[] arr
    int *arr4 = new int[5];
    delete[] arr4;

    return 0;
}