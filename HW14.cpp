#include <iostream> 
#include <string>
#include <chrono>
using namespace std; 


//uso char y no string porque string utiliza memoria dinamica (hace una copia del string por cada llamado recursivo por ende utiliza mas memoria). Char solo va iterando sobre el texto 
bool son_iguales (const char* texto1, const char* texto2);
constexpr bool son_iguales_compilando (const char texto1, const char* texto2);
void miprocesoamedir();
void miprocesoamedir1();

int main (){
    auto startTime = chrono::high_resolution_clock::now();
    miprocesoamedir();
    auto endTime = chrono::high_resolution_clock::now();
    auto elapsedTime = chrono::duration_cast<chrono::nanoseconds>(endTime - startTime);
    cout << "A son_iguales le tomó: " << elapsedTime.count() << " nanosegundos" << endl;

    auto startTime2 = chrono::high_resolution_clock::now();
    miprocesoamedir1();
    auto endTime2 = chrono::high_resolution_clock::now();
    auto elapsedTime2 = chrono::duration_cast<chrono::nanoseconds>(endTime2 - startTime2);
    cout << "A son_iguales_compilando le tomó: " << elapsedTime2.count() << " nanosegundos" << endl; //en compilacion lo tiene ya en memoria por ende no tiene que hacer las comparaciones(ya lo tiene comparado). entonces es mas rapido

    return 0;
}

bool son_iguales (const char* texto1, const char* texto2){
    if (*texto1 == '\0' && *texto2 == '\0') return true; //llego al final de la cadena
    if ((*texto1 == '\0' || *texto2 == '\0')|| (*texto1 != *texto2)) return false; //si no entra en el if anterior pero si en este ya se sabe que una termino antes que otra por ende son distintos

    return son_iguales (texto1+1, texto2+1); //miro lo que me queda de los textos
}

constexpr bool son_iguales_compilando (const char* texto1, const char* texto2){
    if (*texto1 == '\0' && *texto2 == '\0') return true;
    if ((*texto1 == '\0' || *texto2 == '\0')|| (*texto1 != *texto2)) return false; //si no entra en el if anterior pero si en este ya se sabe que una termino antes que otra por ende son distintos

    return son_iguales_compilando (texto1+1, texto2+1); //miro lo que me queda de los textos
}

void miprocesoamedir(){
    const char* t1 = "Argentina, oficialmente conocida como la República Argentina, es un país ubicado en el extremo sur del continente americano. Con una superficie de aproximadamente 2.780.400 km², es el país hispanohablante más extenso del mundo y el segundo en América Latina, después de Brasil. Limita al norte con Bolivia, Paraguay y Brasil; al este con Brasil, Uruguay y el Océano Atlántico; al sur con Chile y el Océano Atlántico; y al oeste con Chile. Esta ubicación le otorga una variedad de climas que van desde el subtropical cálido en el norte hasta el frío y húmedo en el sur, con regiones áridas y templadas en el centro. Según datos recientes, la población de Argentina supera los 40 millones de habitantes. La sociedad argentina es reconocida por su diversidad cultural, resultado de la inmigración europea y la riqueza de las culturas indígenas originarias. Este “crisol de razas” ha contribuido a una identidad nacional única, reflejada en su música, danza, gastronomía y tradiciones. La economía argentina es una de las más grandes de América Latina, con sectores destacados como la agricultura, la ganadería, la industria manufacturera y los servicios. ";
    const char* t2 = "Argentina, oficialmente conocida como la República Argentina, es un país ubicado en el extremo sur del continente americano. Con una superficie de aproximadamente 2.780.400 km², es el país hispanohablante más extenso del mundo y el segundo en América Latina, después de Brasil. Limita al norte con Bolivia, Paraguay y Brasil; al este con Brasil, Uruguay y el Océano Atlántico; al sur con Chile y el Océano Atlántico; y al oeste con Chile. Esta ubicación le otorga una variedad de climas que van desde el subtropical cálido en el norte hasta el frío y húmedo en el sur, con regiones áridas y templadas en el centro. Según datos recientes, la población de Argentina supera los 40 millones de habitantes. La sociedad argentina es reconocida por su diversidad cultural, resultado de la inmigración europea y la riqueza de las culturas indígenas originarias. Este “crisol de razas” ha contribuido a una identidad nacional única, reflejada en su música, danza, gastronomía y tradiciones. La economía argentina es una de las más grandes de América Latina, con sectores destacados como la agricultura, la ganadería, la industria manufacturera y los servicios. ";
    bool iguales = son_iguales (t1,t2);

    cout<<"los textos son iguales?: "<< (iguales ? "si" : "no") << endl;; //si iguales es 1 devuelve si, caso contrario devuelve no

}

void miprocesoamedir1(){
    constexpr const char* t1 = "Argentina, oficialmente conocida como la República Argentina, es un país ubicado en el extremo sur del continente americano. Con una superficie de aproximadamente 2.780.400 km², es el país hispanohablante más extenso del mundo y el segundo en América Latina, después de Brasil. Limita al norte con Bolivia, Paraguay y Brasil; al este con Brasil, Uruguay y el Océano Atlántico; al sur con Chile y el Océano Atlántico; y al oeste con Chile. Esta ubicación le otorga una variedad de climas que van desde el subtropical cálido en el norte hasta el frío y húmedo en el sur, con regiones áridas y templadas en el centro. Según datos recientes, la población de Argentina supera los 40 millones de habitantes. La sociedad argentina es reconocida por su diversidad cultural, resultado de la inmigración europea y la riqueza de las culturas indígenas originarias. Este “crisol de razas” ha contribuido a una identidad nacional única, reflejada en su música, danza, gastronomía y tradiciones. La economía argentina es una de las más grandes de América Latina, con sectores destacados como la agricultura, la ganadería, la industria manufacturera y los servicios. ";
    constexpr const char* t2 = "Argentina, oficialmente conocida como la República Argentina, es un país ubicado en el extremo sur del continente americano. Con una superficie de aproximadamente 2.780.400 km², es el país hispanohablante más extenso del mundo y el segundo en América Latina, después de Brasil. Limita al norte con Bolivia, Paraguay y Brasil; al este con Brasil, Uruguay y el Océano Atlántico; al sur con Chile y el Océano Atlántico; y al oeste con Chile. Esta ubicación le otorga una variedad de climas que van desde el subtropical cálido en el norte hasta el frío y húmedo en el sur, con regiones áridas y templadas en el centro. Según datos recientes, la población de Argentina supera los 40 millones de habitantes. La sociedad argentina es reconocida por su diversidad cultural, resultado de la inmigración europea y la riqueza de las culturas indígenas originarias. Este “crisol de razas” ha contribuido a una identidad nacional única, reflejada en su música, danza, gastronomía y tradiciones. La economía argentina es una de las más grandes de América Latina, con sectores destacados como la agricultura, la ganadería, la industria manufacturera y los servicios. ";
    bool iguales = son_iguales_compilando (t1,t2);

    cout<<"los textos son iguales?: "<< (iguales ? "si" : "no") << endl;;

}