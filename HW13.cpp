#include <iostream> 
#include <string>
#include <memory>
using namespace std; 

struct nodo{
    int data;
    unique_ptr<nodo> siguiente;
};


unique_ptr<nodo> crear_nodo(int valor);

void agregar_adelante(unique_ptr<nodo>& cabeza,int valor);

void agregar_atras (unique_ptr<nodo>& cola, int valor);

void insertar (unique_ptr<nodo>& cabeza,int valor, int posicion);

void borrar (unique_ptr<nodo>& cabeza, int posicion);

void imprimir_lista (const unique_ptr<nodo>& cabeza);


int main(){

    unique_ptr<nodo> c = crear_nodo(1);
    agregar_adelante(c,10);
    agregar_atras(c,20);
    insertar(c,30,30);
    borrar(c,2);
    imprimir_lista(c);
    
    return 0;
}



unique_ptr<nodo> crear_nodo(int valor){
    unique_ptr<nodo> nodo_nuevo = make_unique<nodo>(); //crea el nodo usando unique
    nodo_nuevo->data = valor;
    nodo_nuevo->siguiente = nullptr; // inicializa el siguiente nodo en null

    return nodo_nuevo;
}

void agregar_adelante(unique_ptr<nodo>& cabeza,int valor){
    unique_ptr<nodo> nodo_agregar = crear_nodo(valor);

    nodo_agregar->siguiente = move(cabeza); //asigno el siguiente al nodo a agregar a la cabeza "anterior"

    cabeza = move(nodo_agregar); //nueva cabeza es el nuevo nodo

}

void agregar_atras (unique_ptr <nodo>& cabeza, int valor){
    unique_ptr<nodo> nodo_agregar = crear_nodo(valor);
    if (!cabeza){ //si la cabeza es null es porque la lista esta vacia y el nuevo nodo va a ser la nueva cabeza
        cabeza = move(nodo_agregar);
        return;
    }
    nodo* actual = cabeza.get(); //uso raw pointer para recorrer

    while (actual->siguiente){
        actual = actual->siguiente.get();
    }
    actual->siguiente = move(nodo_agregar); //cuando llego al final, agrego
    return;
}

void insertar (unique_ptr<nodo>& cabeza,int valor, int posicion){
    if (posicion == 0) { //hago push front porque 0 es adelante de todo
        agregar_adelante(cabeza,valor);
        return;
    }
    int indice = 0; //para saber en que indice estoy parado en la lista
    nodo* actual = cabeza.get();//raw para recorrer

    while (actual->siguiente != nullptr && indice < posicion - 1 ){ //si el siguiente al nodo actual es distinto a null o el indice no es el indicado a agregar, sigue
        actual = actual->siguiente.get();
        indice++;
    }

    if (!actual->siguiente){ //si el siguiente al que estoy parado es null es porque debo agregar al final de todo
        cout<<"Posicion fuera de rango"<<endl;
        agregar_atras(cabeza,valor);
        return;
    }
    unique_ptr<nodo> nodo_agregar = crear_nodo(valor);
    
    nodo_agregar->siguiente = move(actual->siguiente); //acomodo los nodos en la posicion indicada (salio del while porque llego a la pos)
    actual->siguiente = move(nodo_agregar);

}

void borrar (unique_ptr<nodo>& cabeza, int posicion){
    if (posicion == 0) {//mismo que insert
        cabeza = move(cabeza->siguiente);
        return;
    }
    int indice = 0;
    nodo* actual = cabeza.get();
    nodo* anterior = NULL; //mantengo un raw al anterior del actual para que cuando llegue a la posicion a borrar pueda reacomodar el puntero anterior 

    while (actual->siguiente != nullptr && indice < posicion){
        anterior = actual;
        actual = actual->siguiente.get();
        indice++;
    }

    if (!actual){ //ya se fue de la lista
        cout<<"Posicion fuera de rango"<<endl;
        anterior->siguiente = NULL;
        return;
    }
    anterior->siguiente = move(actual->siguiente); //acomoda el puntero anterior con el siguiente del actual
    actual->siguiente = NULL;

}

void imprimir_lista (const unique_ptr<nodo>& cabeza){
    nodo* actual = cabeza.get(); //uso para recorrer e ir imprimiendo

    while (actual){
        cout<<""<<actual->data<<"-->"<<endl;
        actual = actual->siguiente.get();
    }
}
