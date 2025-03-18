#include <iostream>

using namespace std;

struct Persona{
    string nombre;
    int edad;
    float estatura;
};

int main(){
    // Cual de las siguientes notaciones es correcta
    // para acceder al noombre de la estructura persona
    // utilizando el apuntador perPtr

    Persona persona;
    Persona *perPtr = &persona;

    string nombre;

    // nombre = perPtr.nombre;
    nombre = perPtr->nombre;
    // nombre = *(perPtr->nombre);
    // nombre = *(perPtr)->nombre;

    // otra opcion
    nombre = (*perPtr).nombre;
    return 0;
}