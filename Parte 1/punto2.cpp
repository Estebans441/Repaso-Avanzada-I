#include <iostream>

using namespace std;

void printArr(int arr[], int t);

int main(){
    // Que hara el siguiente codigo?
    int arr[5] = {1, 2, 3, 4, 5};
    int *ptr = arr;
    *(ptr + 2) = 10;
    // Asignara el valor 10 al tercer elemento del arreglo
    printArr(arr, 5);
    return 0;
}

void printArr(int * arr, int t){
    for(int i = 0 ; i  < t ; i++)
        cout << arr[i] << " ";
    cout << endl;
}