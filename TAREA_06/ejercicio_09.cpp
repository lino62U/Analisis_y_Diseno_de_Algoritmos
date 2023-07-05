// Para resolver el problema de segmentar los clientes en K grupos maximizando la distancia entre clientes de diferentes grupos, podemos utilizar un enfoque greedy. El algoritmo consistirá en asignar en cada paso a un cliente al grupo que maximice la distancia promedio entre los clientes de diferentes grupos. A continuación, se presenta el algoritmo y el código en C++ para implementarlo:

// **Algoritmo Greedy para Segmentar Clientes en K Grupos:**

// 1. Inicializar K grupos vacíos.
// 2. Calcular la matriz de similitud entre todos los clientes en función de sus vectores de características.
// 3. Mientras haya clientes sin asignar a grupos:
//    a. Para cada cliente no asignado, calcular la distancia promedio a todos los clientes de cada grupo.
//    b. Asignar el cliente al grupo que maximice la distancia promedio.
// 4. Devolver los K grupos resultantes.

// **Código en C++:**

// ```cpp
#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

struct Cliente {
    std::vector<double> caracteristicas;
};

// Función para calcular la distancia euclídea entre dos clientes
double calcularDistancia(const Cliente& cliente1, const Cliente& cliente2) {
    double distancia = 0.0;
    for (int i = 0; i < cliente1.caracteristicas.size(); ++i) {
        double dif = cliente1.caracteristicas[i] - cliente2.caracteristicas[i];
        distancia += dif * dif;
    }
    return std::sqrt(distancia);
}

// Función para encontrar el índice del grupo más cercano al cliente
int encontrarGrupoMasCercano(const std::vector<Cliente>& clientes, const std::vector<std::vector<Cliente>>& grupos) {
    int grupo_mas_cercano = -1;
    double distancia_max_promedio = -std::numeric_limits<double>::max();

    for (int i = 0; i < grupos.size(); ++i) {
        double distancia_promedio = 0.0;
        for (const auto& cliente_grupo : grupos[i]) {
            distancia_promedio += calcularDistancia(clientes.back(), cliente_grupo);
        }
        distancia_promedio /= grupos[i].size();

        if (distancia_promedio > distancia_max_promedio) {
            distancia_max_promedio = distancia_promedio;
            grupo_mas_cercano = i;
        }
    }

    return grupo_mas_cercano;
}

// Función para agrupar clientes en K grupos maximizando la distancia entre grupos
std::vector<std::vector<Cliente>> segmentarClientesEnGrupos(const std::vector<Cliente>& clientes, int K) {
    std::vector<std::vector<Cliente>> grupos(K);

    // Asignar cada cliente al grupo más cercano en cada paso
    for (const auto& cliente : clientes) {
        int grupo_mas_cercano = encontrarGrupoMasCercano(clientes, grupos);
        grupos[grupo_mas_cercano].push_back(cliente);
    }

    return grupos;
}

int main() {
    std::vector<Cliente> clientes = {
        {{1, 2}},   // Cliente 0 con características (1, 2)
        {{3, 5}},   // Cliente 1 con características (3, 5)
        {{8, 9}},   // Cliente 2 con características (8, 9)
        {{4, 7}},   // Cliente 3 con características (4, 7)
        {{6, 1}}    // Cliente 4 con características (6, 1)


    };

    int K = 2; // Número de grupos deseados

    std::vector<std::vector<Cliente>> grupos = segmentarClientesEnGrupos(clientes, K);

    // Mostrar los clientes agrupados
    for (int i = 0; i < grupos.size(); ++i) {
        std::cout << "Grupo " << i << ": ";
        for (const auto& cliente : grupos[i]) {
            std::cout << "(" << cliente.caracteristicas[0] << ", " << cliente.caracteristicas[1] << ") ";
        }
        std::cout << std::endl;
    }

    return 0;
}
