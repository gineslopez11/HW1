#include <iostream> 
#include <vector>
using namespace std; //funcines tipos de datos standard

vector<vector<int>> matriz_cuadrada (int n);
void imprimir_celdas (const vector<vector<int>>& matriz, int n);

int main (){
    vector<vector<int>> matriz = matriz_cuadrada(3);
    imprimir_celdas (matriz,3);

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

