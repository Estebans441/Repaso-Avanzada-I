#include <iostream>

using namespace std;

struct Pasajero{
    char nombre[50];
    char apellido[50];
    int documento;
    char nacionalidad[30];
};

struct Asiento{
    int numeroAsiento;
    bool ocupado;
    Pasajero pasajero;
};

struct Vuelo{
    char codigoVuelo[10];
    char origen[50];
    char destino[50];
    char fecha[11];
    Asiento * asientos;
};

struct Avion{
    char empresa[50];
    char codigoAvion[10];
    int numeroAsientos;
    Vuelo * vuelos;
};

struct Compagnia{
    Avion * aviones;
    int numeroAviones;
};

void printArr(int arr[], int t);

int main() {
    // Cuando se pasa un arreglo como parametro a una funcion, este se pasa como una copia?
    int arr[5] = {0,1,2,3,4};
    printArr(arr, 5);
    return 0;
}


void printArr(int arr[], int t){

}