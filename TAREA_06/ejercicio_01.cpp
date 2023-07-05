#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

struct Contenedor
{
    float peso;
};

typedef std::vector<Contenedor>::iterator it;
//Diseñe un algoritmo que intente maximizar el número de toneladas cargadas.
it seleccionCrit3( std::vector<Contenedor> & C)
{
    return std::max_element(C.begin(),C.end(),[](const Contenedor &a, const Contenedor &b ){  return a.peso < b.peso;} );
}

// maximizar cantidad de contenedores
it seleccionCrit2(std::vector<Contenedor> & C)
{
    return std::min_element(C.begin(),C.end(),[](const Contenedor &a, const Contenedor &b ){  return a.peso < b.peso;} );
}

void getContenedores(int K, std::vector<Contenedor> &candidatos, std::vector<Contenedor> &solucion, it (*fun) (std::vector<Contenedor> &))
{
    solucion.clear();
    int pesoAct = 0;
    while (pesoAct < K)
    {
        // seleccionar el mejor candidato
        it i = fun(candidatos);
        // std::cout<<i->peso<<" ";
        if(pesoAct + i->peso <= K)  
        {
            int numCont = 1;
            float beneficio = numCont*i->peso;
            solucion.push_back(Contenedor{beneficio});
            pesoAct+= i->peso;
        }else{
            int numBag = K-pesoAct;
            std::cout<<"Asdad: "<<K-pesoAct<<std::endl;
            float beneficio = std::round((numBag*i->peso/i->peso )*1000)/1000;
            
            solucion.push_back(Contenedor{ beneficio});
            pesoAct=K;
        }
        if(candidatos.empty()) return;

        candidatos.erase(i);
    }
    


}

void imprimir( std::vector<Contenedor>& contenedores)
{
    float m=0;
    for (const Contenedor& a : contenedores) {
        m+=a.peso;
        std::cout<<a.peso<<" ";
        
    }   
    std::cout<<std::endl;
    std::cout<<"Peso total: "<<m<<std::endl;
}

int main() {
    int capacidad_buque = 100; // Capacidad máxima del buque en toneladas
    std::vector<Contenedor> contenedores = {
        {30},
        {20},
        {50},
        {40},
        {10}
    };
    std::vector<Contenedor> solucion;
    getContenedores(capacidad_buque, contenedores,solucion,seleccionCrit2);
    imprimir(solucion);
    std::vector<Contenedor> contenedores2 = {
        {30},
        {20},
        {50},
        {40},
        {10}
    };
    std::vector<Contenedor> solucion2;
    getContenedores(capacidad_buque, contenedores2,solucion2,seleccionCrit3);
    imprimir(solucion2);
    
    
    return 0;
}