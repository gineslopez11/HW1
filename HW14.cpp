#include <iostream> 
#include <string>
#include <chrono>
using namespace std; 

bool son_iguales (const char* texto1, const char* texto2);
constexpr bool son_iguales_compilando (const char* texto1, const char* texto2);

int main (){
    const char* t1 = "Hola como estaSSSSSSSSSSSSSSSSSSSSSSSSSS";
    const char* t2 = "Hola como estaSSSSSSSSSSSSSSSSSSSSSSSSSS";
    bool iguales = son_iguales (t1,t2);
    cout<<"los textos son iguales?: "<< (iguales ? "si" : "no") << endl;;

    auto startTime = chrono::high_resolution_clock::now();
    son_iguales(t1,t2);
    auto endTime = chrono::high_resolution_clock::now();
    auto elapsedTime = chrono::duration_cast<chrono::nanoseconds>(endTime - startTime);
    cout << "A son_iguales le tomó: " << elapsedTime.count() << " nanosegundos" << endl;

    auto startTime2 = chrono::high_resolution_clock::now();
    son_iguales_compilando(t1,t2);
    auto endTime2 = chrono::high_resolution_clock::now();
    auto elapsedTime2 = chrono::duration_cast<chrono::nanoseconds>(endTime2 - startTime2);
    cout << "A son_iguales_compilando le tomó: " << elapsedTime2.count() << " nanosegundos" << endl;

    return 0;
}

bool son_iguales (const char* texto1, const char* texto2){
    if (*texto1 == '\0' && *texto2 == '\0') return true;
    if ((*texto1 == '\0' || *texto2 == '\0')|| (*texto1 != *texto2)) return false; //si no entra en el if anterior pero si en este ya se sabe que una termino antes que otra por ende son distintos

    return son_iguales (texto1+1, texto2+1); //miro lo que me queda de los textos
}

constexpr bool son_iguales_compilando (const char* texto1, const char* texto2){
    if (*texto1 == '\0' && *texto2 == '\0') return true;
    if ((*texto1 == '\0' || *texto2 == '\0')|| (*texto1 != *texto2)) return false; //si no entra en el if anterior pero si en este ya se sabe que una termino antes que otra por ende son distintos

    return son_iguales_compilando (texto1+1, texto2+1); //miro lo que me queda de los textos
}