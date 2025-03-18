#include <iostream>

using namespace std;

void fillArr(int *arr, int size);
void printArr(int *arr, int size);

int main(){
    // Funcion para asignar memoria dinamica para un arreglo
    // a. malloc
    int *arr = (int *)malloc(5 * sizeof(int)); // es para C
    fillArr(arr, 5);
    printArr(arr, 5);
    
    // b. calloc
    int *arr2 = (int *)calloc(5, sizeof(int)); // es para C (inicializa en 0)
    fillArr(arr2, 5);
    printArr(arr2, 5);

    // c. new
    int *arr3 = new int[5];
    fillArr(arr3, 5);
    printArr(arr3, 5);

    // d. free : para liberar la memoria
    free(arr);
    free(arr2);
    delete[] arr3;


    return 0;
}

// Fill arr
void fillArr(int *arr, int size){
    for(int i = 0; i < size; i++){
        arr[i] = i;
    }
}

void printArr(int *arr, int size){
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}