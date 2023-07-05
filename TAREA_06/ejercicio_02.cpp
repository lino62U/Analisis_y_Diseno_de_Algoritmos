#include <iostream>
#include <vector>
#include <algorithm>

struct Programa {
    int espacio_requerido;
    // Puedes agregar más atributos si es necesario.
};

bool compararPorEspacio(const Programa& p1, const Programa& p2) {
    return p1.espacio_requerido > p2.espacio_requerido; // Ordenamos de forma no creciente según el espacio requerido.
}

bool compararPorEspacio2(const Programa& p1, const Programa& p2) {
    return p1.espacio_requerido < p2.espacio_requerido; // Ordenamos de forma no creciente según el espacio requerido.
}

int maximizarProgramasAlmacenados(int espacio_disponible, std::vector<Programa>& programas, std::vector<Programa>& solucion,  bool(*critSeleccion)(const Programa& p1, const Programa& p2) ) {
    std::sort(programas.begin(), programas.end(), critSeleccion);

    int programas_almacenados = 0;
    solucion.clear();
    for (const Programa& programa : programas) {
        if (programa.espacio_requerido <= espacio_disponible) {
            espacio_disponible -= programa.espacio_requerido;
            solucion.push_back(programa);
            programas_almacenados++;
        }
    }
    return programas_almacenados;
}


void imprimir( std::vector<Programa>& pr)
{
    int m=0;
    for (const Programa& a : pr) {
        m+=a.espacio_requerido;
        std::cout<<a.espacio_requerido<<" ";
        
    }   
    std::cout<<std::endl;
    std::cout<<"Peso total: "<<m<<std::endl;
}



int main() {
    int espacio_disponible = 100; // Capacidad máxima del disco en megabytes
    std::vector<Programa> programas = {
        {30},
        {20},
        {50},
        {40},
        {10}
    };
    std::vector<Programa> solucion;
    int programas_almacenados = maximizarProgramasAlmacenados(espacio_disponible, programas,solucion, compararPorEspacio2);

    std::cout << "Número de programas almacenados: " << programas_almacenados << std::endl;
    imprimir(solucion);
    
    int programas_almacenados2 = maximizarProgramasAlmacenados(espacio_disponible, programas,solucion, compararPorEspacio);

    std::cout << "Número de programas almacenados: " << programas_almacenados2 << std::endl;
    imprimir(solucion);
    
    
    return 0;
}
