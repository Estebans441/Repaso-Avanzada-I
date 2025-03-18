#include <iostream>
#include <fstream>

using namespace std;

int main(){
    // Cual es el modo correcto para abrir un archivo de texto en modo escritura?
    ofstream file("../archivo.txt", ios::in);  // Modo lectura mal
    ifstream file("../archivo.txt", ios::out); // Modo escritura mal
    ofstream file("../archivo.txt", ios::out); // Modo escritura bien
    fstream file("../archivo.txt", ios::in);   // Modo lectura

    file << "Hola mundo!" << endl;

    file.close();

    return 0;
}