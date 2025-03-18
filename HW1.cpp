#include <iostream> //se usa para imprimir
#include <fstream>
#include <sstream>
#include <vector>
using namespace std; //funcines tipos de datos standard

enum nivelseveridad{
    DEBUG = 0,
    INFO = 1,
    WARNING = 2,
    ERROR = 3,
    CRITICAL = 4
};

vector<vector<int>> matriz_cuadrada (int n);
void log_message(string mensaje, int severidad);

void imprimir_celdas (const vector<vector<int>>& matriz, int n);

int main(){
    vector<vector<int>> matriz = matriz_cuadrada(3);
    imprimir_celdas (matriz,3);
    log_message("error", nivelseveridad(3))
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

        cout << "M [" + to_string(fila) + "] [" + to_string(columna) + "] = " + to_string(matriz[fila][columna]) << endl;
    }
}

void log_message(string mensaje, int severidad){

    ofstream outfile("escribirHW2.txt", ios::app);
    if(outfile.is_open()){
        outfile<<"["+to_string(severidad)+"] <"+mensaje+"> ";
    }

}