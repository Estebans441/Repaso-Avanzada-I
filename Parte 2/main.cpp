#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

// 1
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
//------------------------
struct Vuelo{
    char codigoVuelo[10];
    char origen[50];
    char destino[50];
    char fecha[11];
    Asiento * asientos;

    void imprimirVuelo(){
        cout << "Codigo Vuelo: " << codigoVuelo << endl;
        cout << "Origen: " << origen << endl;
        cout << "Destino: " << destino << endl;
        cout << "Fecha: " << fecha << endl;
        cout << "---" << endl;
    }
};

struct Avion{
    char empresa[50];
    char codigoAvion[10];
    int numeroAsientos;
    Vuelo * vuelos;
    int numeroVuelos;

    void imprimirAvion(){
        cout << "------------------------------" << endl;
        cout << "Empresa: " << empresa << endl;
        cout << "Codigo Avion: " << codigoAvion << endl;
        cout << "Numero Asientos: " << numeroAsientos << endl;
        cout << "Numero Vuelos: " << numeroVuelos << endl;
        cout << "---- Vuelos ----" << endl;
        for(int i = 0; i < numeroVuelos; i++){
            (vuelos + i) -> imprimirVuelo();
        }
        cout << "------------------------------" << endl;
    }
};

struct Compania{
    Avion * aviones;
    int numeroAviones;

    void imprimirCompania(){
        cout << "------------------------------" << endl;
        cout << "---- Datos de la Compania ----" << endl;
        cout << "------------------------------" << endl;
        cout << "Numero Aviones: " << numeroAviones << endl;
        cout << "---- Aviones ----" << endl;
        cout << "------------------------------" << endl;
        for(int i = 0; i < numeroAviones; i++){
            (aviones + i) -> imprimirAvion();
        }
    }
};

// 2
void agregarAvion(Compania &c, Avion a);
// 3
Avion * buscarAvion(Compania &c, char codigoAvion[]);
// 4
void agregarVueloAvion(Compania &c, char cadenaVuelo[]);
// 5
void leerArchivo(Compania &comp);
// 6
void generarReporteVuelosCiudad(Compania &c, char origen[]);

// Utils
void agregarVueloArr(Vuelo * &vuelos, Vuelo v, int &numeroVuelos);


int main() {
    Compania * c = new Compania();
    c -> aviones = new Avion;
    c -> numeroAviones = 0;
    leerArchivo(*c);

    // c -> imprimirCompania();
    char origen[50];
    strcpy(origen, "Miami");
    generarReporteVuelosCiudad(*c, origen);
    return 0;
}

// 2
void agregarAvion(Compania &c, Avion a){
    Avion * temp = new Avion[c.numeroAviones + 1];
    for(int i = 0; i < c.numeroAviones; i++){
        *(temp + i) = *(c.aviones + i);
    }
    delete [] c.aviones;

    *(temp + c.numeroAviones) = a;
    c.aviones = temp;
    c.numeroAviones++;
}

// 3
Avion * buscarAvion(Compania &c, char codigoAvion[]){
    for(int i = 0; i < c.numeroAviones; i++){
        if(strcmp((c.aviones+ i) -> codigoAvion, codigoAvion) == 0){
            return c.aviones + i;
        }
    }
    cout << "No se encontro el avion" << endl;
    return nullptr;
}


void agregarVueloAvion(Compania &c, char cadenaVuelo[]){
    // usar strtok para descomponer la cadena que viene de la forma
    // 6052,AV1120,Bogota,Rio de Janeiro,21/11/2024
    Vuelo v = Vuelo();
    char * token = strtok(cadenaVuelo, ",");
    
    // Codigo del Avion
    char codigoAvion[10];
    strcpy(codigoAvion, token);
    token = strtok(NULL, ","); // avanzar al siguiente token

    // Codigo del Vuelo
    strcpy(v.codigoVuelo, token);
    token = strtok(NULL, ","); // avanzar al siguiente token
    
    // Origen
    strcpy(v.origen, token);    
    token = strtok(NULL, ","); // avanzar al siguiente token
    
    // Destino
    strcpy(v.destino, token);
    token = strtok(NULL, ","); // avanzar al siguiente token
    
    // Fecha
    strcpy(v.fecha, token);
    token = strtok(NULL, ","); // avanzar al siguiente token

    // Buscar el avion
    Avion * a = buscarAvion(c, codigoAvion);
    if(a != nullptr){
        agregarVueloArr(a -> vuelos, v, a -> numeroVuelos);
    }
}

void agregarVueloArr(Vuelo * &vuelos, Vuelo v, int &numeroVuelos){
    Vuelo * temp = new Vuelo[numeroVuelos + 1];
    for(int i = 0; i < numeroVuelos; i++){
        *(temp + i) = *(vuelos + i);
    }
    delete [] vuelos;

    *(temp + numeroVuelos) = v;
    vuelos = temp;
    numeroVuelos++;
}

// 5
void leerArchivo(Compania &comp){
    ifstream archivo("../vuelos.txt");
    if(!archivo.is_open()){
        cout << "No se pudo abrir el archivo" << endl;
        return;
    }

    char linea[100];
    while(!archivo.eof()){
        // Nombre compania
        archivo.getline(linea, 100);
        char * empresa = new char[50];
        strcpy(empresa, linea);

        
        // Aviones
        archivo.getline(linea, 100);
        char * token = strtok(linea, "-");
        while(token != NULL){
            Avion a;
            strcpy(a.empresa, empresa);
            strcpy(a.codigoAvion, token);

            // Numero de asientos
            token = strtok(NULL, ",");
            a.numeroAsientos = atoi(token);
            
            // Inicializar vuelos
            a.vuelos = new Vuelo;
            a.numeroVuelos = 0;

            agregarAvion(comp, a);

            // Avanzar al siguiente avion
            token = strtok(NULL, "-");
        }

        // Vuelos
        archivo.getline(linea, 100);
        while(strcmp(linea, "#") != 0){
            agregarVueloAvion(comp, linea);
            archivo.getline(linea, 100);
        }
    }

    archivo.close();
}

// 6
void generarReporteVuelosCiudad(Compania &c, char origen[]){
    int vuelos = 0;
    Vuelo * vuelosEncontrados = new Vuelo;
    for(int i = 0 ; i < c.numeroAviones; i++){
        for(int j = 0; j < (c.aviones + i) -> numeroVuelos; j++){
            if(strcmp(((c.aviones + i) -> vuelos + j) -> origen, origen) == 0){
                agregarVueloArr(vuelosEncontrados, *((c.aviones + i) -> vuelos + j), vuelos);
            }
        }
    }

    if(vuelos == 0){
        cout << "No se encontraron vuelos con origen en " << origen << endl;
        return;
    }

    // Imprimir vuelos
    cout << "Vuelos con origen en " << origen << endl;
    cout << "---" << endl;
    for(int i = 0; i < vuelos; i++){
        (vuelosEncontrados + i) -> imprimirVuelo();
    }

    // Nombre de archivos
    char * archivo = new char[50];
    strcpy(archivo, "../vuelos");
    strcat(archivo, origen);


    // Nombre archivo txt
    char * archivoTxt = new char[50];
    strcpy(archivoTxt, archivo);
    strcat(archivoTxt, ".txt");

    // Nombre archivo bin
    char * archivoBin = new char[50];
    strcpy(archivoBin, archivo);
    strcat(archivoBin, ".bin");

    // Guardar en archivo
    cout << "Guardando en " << archivoTxt << endl;
    ofstream file(archivoTxt);
    for(int i = 0; i < vuelos; i++){
        file << "Codigo Vuelo: " << (vuelosEncontrados + i) -> codigoVuelo << endl;
        file << "Origen: " << (vuelosEncontrados + i) -> origen << endl;
        file << "Destino: " << (vuelosEncontrados + i) -> destino << endl;
        file << "Fecha: " << (vuelosEncontrados + i) -> fecha << endl;
        file << "---" << endl;
    }
    file.close();

    // Guardar en archivo binario
    cout << "Guardando en " << archivoBin << endl;
    ofstream fileBin(archivoBin, ios::binary);
    for(int i = 0; i < vuelos; i++){
        fileBin.write((char *) (vuelosEncontrados + i), sizeof(Vuelo));
    }
    fileBin.close();
}
