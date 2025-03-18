#include <iostream>

using namespace std;

int main(){
    // El operador new se utiliza para liberar memoria asignada dinamicamente
    // Falso
    // se utiliza para asignar memoria dinamicamente
    int *p = new int;
    // para eliminar se utiliza delete
    delete p;
    return 0;
}