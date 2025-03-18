#include <iostream>
#include <fstream>
using namespace std;

int main(){
    // En c++ al abrir un archivo solamente se puede
    // abrir como escritura o como lectura
    // pero no ambos
    // Falso

    fstream file("../archivo.txt");
    file << "Hola" << endl;

    file.close();
    file.open("../archivo.txt");

    string line;
    file >> line;
    cout << line << endl;

    file.close();
    return 0;
}