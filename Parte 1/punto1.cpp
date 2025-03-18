#include <iostream>

using namespace std;

void modifyArr(int * arr, int t);
void printArr(int arr[], int t);

int main() {
    // Cuando se pasa un arreglo como parametro a una funcion, este se pasa como una copia?
    int arr[5] = {0,1,2,3,4};
    printArr(arr, 5);
    modifyArr(arr,5);
    printArr(arr, 5); // Falso
    return 0;
}

void modifyArr(int * arr, int t){
    for(int i = 0 ; i  < t ; i++)
        arr[i]++;
}

void printArr(int arr[], int t){
    for(int i = 0 ; i  < t ; i++)
        cout << arr[i] << " ";
    cout << endl;
}