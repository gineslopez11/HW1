#include <iostream> 
#include <string>
#include <memory>
using namespace std; 

struct nodo{
    int data;
    unique_ptr<nodo> siguiente;
    nodo(int val) : data(val), siguiente(nullptr){}
};


unique_ptr<nodo> crear_nodo(int valor);

void agregar_adelante(unique_ptr<nodo>& cabeza,int valor);

void agregar_atras (unique_ptr <nodo>& cola, int valor);

void insertar (unique_ptr<nodo>& cabeza,int valor, int posicion);

void borrar (unique_ptr<nodo>& cabeza, int posicion);

void imprimir_lista (unique_ptr<nodo>& cabeza);


int main(){

    unique_ptr<nodo> c = crear_nodo(1);
    agregar_adelante(c,10);
    agregar_atras(c,20);
    insertar(c,30,1);
    borrar(c,1);
    imprimir_lista(c);

    
    return 0;
}



unique_ptr<nodo> crear_nodo(int valor){
    return make_unique<nodo> (valor);
}

void agregar_adelante(unique_ptr<nodo>& cabeza,int valor){
    unique_ptr<nodo> nodo_agregar = crear_nodo(valor);

    nodo_agregar->siguiente = move(cabeza);

    cabeza = move(nodo_agregar);

}

void agregar_atras (unique_ptr <nodo>& cabeza, int valor){
    unique_ptr<nodo> nodo_agregar = crear_nodo(valor);
    if (!cabeza){
        cabeza = move(nodo_agregar);
        return;
    }
    nodo* actual = cabeza.get();

    while (actual->siguiente){
        actual = actual->siguiente.get();
    }
    actual->siguiente = move(nodo_agregar);
    return;
}

void insertar (unique_ptr<nodo>& cabeza,int valor, int posicion){
    if (posicion == 0) {
        agregar_adelante(cabeza,valor);
        return;
    }
    int indice = 0;
    nodo* actual = cabeza.get();

    while (actual && indice < posicion - 1 ){
        actual = actual->siguiente.get();
        indice++;
    }

    if (!actual){
        cout<<"Posicion fuera de rango"<<endl;
        agregar_atras(cabeza,valor);
    }
    unique_ptr<nodo> nodo_agregar = crear_nodo(valor);
    
    nodo_agregar->siguiente = move(actual->siguiente);  
    actual->siguiente = move(nodo_agregar);

}

void borrar (unique_ptr<nodo>& cabeza, int posicion){
    if (posicion == 0) {
        cabeza = move(cabeza->siguiente);
        return;
    }
    int indice = 0;
    nodo* actual = cabeza.get();
    nodo* anterior = NULL;

    while (actual->siguiente && indice < posicion - 1 ){
        anterior = actual;
        actual = actual->siguiente.get();
        indice++;
    }

    if (!actual->siguiente){
        cout<<"Posicion fuera de rango"<<endl;
    }
    anterior->siguiente = move(actual->siguiente);

}

void imprimir_lista (unique_ptr<nodo>& cabeza){
    unique_ptr<nodo> actual = move(cabeza);

    while (actual){
        cout<<""<<actual->data<<"-->"<<endl;
        actual = move(actual->siguiente);
    }
}
