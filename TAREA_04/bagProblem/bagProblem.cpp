#include <iostream>
#include <vector>
#include <algorithm>

struct Objeto {
    int peso;
    int valor;
};

bool compararPorRatio(const Objeto& a, const Objeto& b) {
    double ratioA = static_cast<double>(a.valor) / a.peso;
    double ratioB = static_cast<double>(b.valor) / b.peso;
    return ratioA > ratioB;
}

std::vector<Objeto> obtenerMochila(int capacidadMochila, std::vector<Objeto> objetos) {
    std::sort(objetos.begin(), objetos.end(), compararPorRatio);
    
    std::vector<Objeto> mochila;
    int capacidadRestante = capacidadMochila;
    
    for (const Objeto& objeto : objetos) {
        if (objeto.peso <= capacidadRestante) {
            mochila.push_back(objeto);
            capacidadRestante -= objeto.peso;
        }
        else {
            double fraccion = static_cast<double>(capacidadRestante) / objeto.peso;
            Objeto objetoFraccionado;
            objetoFraccionado.peso = capacidadRestante;
            objetoFraccionado.valor = static_cast<int>(fraccion * objeto.valor);
            mochila.push_back(objetoFraccionado);
            break;
        }
    }
    
    return mochila;
}

int main() {
    int capacidadMochila = 50;
    std::vector<Objeto> objetos = {{10, 60}, {20, 100}, {30, 120}};
    
    std::vector<Objeto> mochila = obtenerMochila(capacidadMochila, objetos);
    
    std::cout << "Objetos en la mochila: " << std::endl;
    for (const Objeto& objeto : mochila) {
        std::cout << "Peso: " << objeto.peso << ", Valor: " << objeto.valor << std::endl;
    }
    
    return 0;
}
