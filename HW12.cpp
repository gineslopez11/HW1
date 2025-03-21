#include <iostream> //se usa para imprimir
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

enum nivelseveridad{ //en vez de usar numeros arbitrarios uso enum para representar de manera mas clara los niveles
    DEBUG,
    INFO,
    WARNING,
    ERROR,
    CRITICAL
};

void log_message(string mensaje, enum nivelseveridad severidad);

const char* etiquetar (enum nivelseveridad severidad);

void log_message(string mensaje, string archivo, int linea_de_codigo);

void log_message(string mensaje_acceso, string nombre_usuario);

int main (){

    int seleccion;
    string mensaje;
    cout << "Ingrese numero de severidad: ";
    cin >> seleccion;
    cin.ignore();
    cout << "Ingrese mensaje de error: ";
    getline(cin, mensaje);
    log_message(mensaje, static_cast<nivelseveridad>(seleccion));

    //EJ 2b simulacion de error
    try{
        int x = 0;
        if (x == 0){
            throw runtime_error("Division por cero"); //simulo un error de division por cero
        }
        cout<<"Continua... " <<endl;
    }
    catch (runtime_error& err){ //como en este caso da error, escribe en el archivo
        string mensaje = "Division por cero";
        string archivo = "main.cpp";
        int linea = 47;

        log_message(mensaje, ERROR);

        log_message(mensaje, archivo, linea);

        string mensaje_acceso = "Access Denied";  
        string nombre_usuario = "UsuarioA";  
        log_message(mensaje_acceso, nombre_usuario);

        cout << "Se ha producido un error: " << mensaje << endl;
        return 1;
    }

    return 0;
}

const char* etiquetar (enum nivelseveridad severidad){ //etiqueto los niveles de sev. para poder pasarlos a char cuando lo pasan a la funcion (luego es mas facil de manejar)
    switch(severidad){
        case DEBUG: return "DEBUG";
        case INFO: return "INFO";
        case WARNING: return "WARNING";
        case ERROR: return "ERROR";
        case CRITICAL: return "CRITICAL";
        default: return "DESCONOCIDO";
    }
}

void log_message(string mensaje, enum nivelseveridad severidad){

    const char* etiqueta = etiquetar(severidad);
    ofstream outfile("escribirHW2.txt", ios::app); //abro el archivo en modo de escritura y todo lo que escriba se agrega al final del archivo
    if(outfile.is_open()){
        outfile<<"["<<etiqueta<<"] <"<<mensaje<<"> \n"; //si se puede abrir escribe [etiqueta] <<mensaje<<
        outfile.close(); }
    else { //si no se puede abrir da error
        cerr << "Error al abrir el archivo de log." << endl;  
    }


}

void log_message(string mensaje, string archivo, int linea_de_codigo){

    ofstream outfile("escribirHW2.txt", ios::app); //hago lo mismo que el anterior
    if(outfile.is_open()){
        outfile<<""<<mensaje<<" (nombre del archivo: "<<archivo<<") ; linea: "<<linea_de_codigo<<" \n";
        outfile.close(); }
    else {
        cerr << "Error al abrir el archivo de log." << endl; 
    }
}

void log_message(string mensaje_acceso, string nombre_usuario){
    ofstream outfile("escribirHW2.txt", ios::app);//mismo
    if(outfile.is_open()){
        outfile<<"[SECURITY] "<<mensaje_acceso<<" <"<<nombre_usuario<<"> \n";
        outfile.close(); }
    else {
        cerr << "Error al abrir el archivo de log." << endl;  
    }
}