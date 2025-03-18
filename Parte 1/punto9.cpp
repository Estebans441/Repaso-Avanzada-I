#include <iostream>

using namespace std;

struct Persona{
    string nombre;
    int edad;
    float estatura;

    void printInfo(){
        cout << "Nombre: " << nombre << endl;
        cout << "Edad: " << edad << endl;
        cout << "Estatura: " << estatura << endl;
    }
};

int main(){
    Persona persona;
    persona.nombre = "Esteban";
    persona.edad = 22;
    persona.estatura = 1.75;
    persona.printInfo();
    return 0;
}