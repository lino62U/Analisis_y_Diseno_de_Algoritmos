/*
    C   ->  conjunto de candidatos
    S   ->  conjunto de seleccionados
    R   ->  conjunto de rechazados

*/

#include "iostream"
#include "vector"
#include <algorithm>
#include <cmath>
using namespace std;

#define INF 256

struct Moneda
{
    int Tipo;
    int Cantidad = INF;
    Moneda(int i)
    {
        Tipo = i;
    }
    Moneda(int i, int cant)
    {
        Tipo = i;
        Cantidad = cant;
    }
};



bool algoritmoVorazMoneda(int P, vector<Moneda>& candidatos, vector<Moneda>&solucion)
{
    int act=0;
    int j = candidatos.size() - 1;
    
    while (act!=P)
    {
        if(j==-1 && act!=P) { return false;}
        if(candidatos[j].Tipo < (P-act))
        {
            int typeMoneda = candidatos[j].Tipo;
            
            int numMonedas = floor( (P-act)/typeMoneda);

            solucion.push_back(Moneda(typeMoneda, numMonedas));
            act+=(numMonedas*typeMoneda);

        }
        
        j--;
    }
    return true;
}


int main()
{
    //vector<Moneda> monedas = {1, 90,100};
    vector<Moneda> monedas = {1, 2, 5, 10, 20, 50, 100, 200};
    vector<Moneda>solucion;
    int P = 389;
    if(algoritmoVorazMoneda(P, monedas, solucion))
    {
        cout<<"Repartir "<<P<<" centimos"<<endl;
        cout<<"Solucion: "<<endl;
        cout<<"Moneda\tCantidad"<<endl;
        for (auto i: solucion)
        {
            std::cout<<i.Tipo<<"\t"<<i.Cantidad<<endl;
        }
    }
    else
        cout<<"No hay solucion"<<endl;

    
    return 0;
}
