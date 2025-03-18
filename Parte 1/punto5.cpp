#include <iostream>

using namespace std;

int main(){
    // cual no es correcta
    char frase[] = "1. Esta es una frase";
    const char * frase2 = "2. Esta es una frase";
    const string frase3 = "3. Esta es una frase";

    // string * frase4 = "Esta es una frase"; // Error
    // Forma de utilizar algo asi
    string * frase4 = new string("4. Esta es una frase");
    // o
    string * frases = new string[4];
    frases[0] = frase;
    frases[1] = frase2;
    frases[2] = frase3;
    frases[3] = *frase4;

    for (int i = 0; i < 4; i++){
        cout << frases[i] << endl;
    }
    return 0;
}