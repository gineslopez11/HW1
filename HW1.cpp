#include <iostream> //se usa para imprimir
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std; //funcines tipos de datos standard

enum nivelseveridad{
    DEBUG,
    INFO,
    WARNING,
    ERROR,
    CRITICAL
};

vector<vector<int>> matriz_cuadrada (int n);

void imprimir_celdas (const vector<vector<int>>& matriz, int n);

void log_message(string mensaje, enum nivelseveridad severidad);

const char* etiquetar (enum nivelseveridad severidad);

int main(){
    vector<vector<int>> matriz = matriz_cuadrada(3);
    imprimir_celdas (matriz,3);
    log_message("hay error", ERROR);
    return 0;
}

vector<vector<int>> matriz_cuadrada (int n){
    vector<vector<int>> matriz(n, vector<int>(n));
    int valor_final = n*n;

    for (int i = n-1; i >= 0; i--){
        for (int j = n-1; j >= 0; j--){
            matriz[i][j] = valor_final;
            valor_final -= 1;
        }
    }

    return matriz;
}

void imprimir_celdas (const vector<vector<int>>& matriz, int n){
    for (int i = n*n - 1; i >= 0; i--){
        int fila = i / n;      
        int columna = i % n; 

        cout << "M [" << fila << "] [" << columna << "] = " << matriz[fila][columna] << endl;
    }
}

const char* etiquetar (enum nivelseveridad severidad){
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
    ofstream outfile("escribirHW2.txt", ios::app);
    if(outfile.is_open()){
        outfile<<"["<<etiqueta<<"] <"<<mensaje<<"> \n";
        outfile.close(); }


}