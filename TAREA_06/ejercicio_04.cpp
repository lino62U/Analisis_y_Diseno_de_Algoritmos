#include <iostream>
#include <vector>
#include <algorithm>

// Representación de una arista (u, v) en el grafo.
struct Arista {
    int u;
    int v;
};

// Función para agregar una arista al grafo.
void agregarArista(std::vector<Arista>& grafo, int u, int v) {
    grafo.push_back({u, v});
}

// Estructura para representar el conjunto de nodos del recubrimiento.
struct Recubrimiento {
    std::vector<bool> nodos_seleccionados;

    explicit Recubrimiento(int num_nodos) : nodos_seleccionados(num_nodos, false) {}

    void agregarNodo(int nodo) {
        nodos_seleccionados[nodo] = true;
    }
};

// Algoritmo greedy para obtener un recubrimiento de G.
Recubrimiento obtenerRecubrimiento(const std::vector<Arista>& grafo, int num_nodos) {
    Recubrimiento recubrimiento(num_nodos);
    std::vector<Arista> aristas_restantes = grafo;

    while (!aristas_restantes.empty()) {
        // Tomar una arista (u, v) de aristas_restantes.
        int u = aristas_restantes.back().u;
        int v = aristas_restantes.back().v;
        aristas_restantes.pop_back();

        // Agregar ambos nodos u y v al conjunto recubrimiento.
        recubrimiento.agregarNodo(u);
        recubrimiento.agregarNodo(v);

        // Eliminar todas las aristas incidentes en u y v de aristas_restantes.
        aristas_restantes.erase(
            std::remove_if(aristas_restantes.begin(), aristas_restantes.end(),
                [u, v](const Arista& arista) {
                    return arista.u == u || arista.v == u || arista.u == v || arista.v == v;
                }),
            aristas_restantes.end()
        );
    }

    return recubrimiento;
}

int main() {
    std::vector<Arista> grafo;
    agregarArista(grafo, 1, 2);
    agregarArista(grafo, 1, 3);
    agregarArista(grafo, 2, 3);
    agregarArista(grafo, 3, 4);
    agregarArista(grafo, 4, 5);

    int num_nodos = 6; // Se asume que los nodos están numerados desde 1 hasta num_nodos.

    Recubrimiento recubrimiento = obtenerRecubrimiento(grafo, num_nodos);

    std::cout << "Nodos en el recubrimiento: ";
    for (int nodo = 1; nodo <= num_nodos; ++nodo) {
        if (recubrimiento.nodos_seleccionados[nodo]) {
            std::cout << nodo << " ";
        }
    }
    std::cout << std::endl;

    return 0;
}




/**
 * parte B
 * 
 *
 */
/*
#include <iostream>
#include <vector>
#include <algorithm>

// Representación de una arista (u, v) en el grafo.
struct Arista {
    int u;
    int v;
};

// Función para agregar una arista al grafo.
void agregarArista(std::vector<Arista>& grafo, int u, int v) {
    grafo.push_back({u, v});
}

// Función para calcular el grado de incidencia de cada nodo en el grafo.
std::vector<int> calcularGradoIncidencia(int num_nodos, const std::vector<Arista>& grafo) {
    std::vector<int> grado_incidencia(num_nodos + 1, 0);
    for (const Arista& arista : grafo) {
        grado_incidencia[arista.u]++;
        grado_incidencia[arista.v]++;
    }
    return grado_incidencia;
}

// Función para seleccionar el nodo con mayor grado de incidencia entre los nodos aún no seleccionados.
int seleccionarNodoConMayorGrado(const std::vector<int>& grado_incidencia, const std::vector<bool>& nodos_seleccionados) {
    int max_grado = 0;
    int max_grado_nodo = -1;
    for (size_t i = 1; i < grado_incidencia.size(); ++i) {
        if (!nodos_seleccionados[i] && grado_incidencia[i] > max_grado) {
            max_grado = grado_incidencia[i];
            max_grado_nodo = i;
        }
    }
    return max_grado_nodo;
}

// Estructura para representar el conjunto de nodos del recubrimiento.
struct Recubrimiento {
    std::vector<bool> nodos_seleccionados;

    explicit Recubrimiento(int num_nodos) : nodos_seleccionados(num_nodos + 1, false) {}

    void agregarNodo(int nodo) {
        nodos_seleccionados[nodo] = true;
    }
};

// Algoritmo greedy para obtener un recubrimiento de G seleccionando el nodo con mayor grado en cada paso.
Recubrimiento obtenerRecubrimientoGreedy(const std::vector<Arista>& grafo, int num_nodos) {
    Recubrimiento recubrimiento(num_nodos);
    std::vector<Arista> aristas_restantes = grafo;
    std::vector<int> grado_incidencia = calcularGradoIncidencia(num_nodos, grafo);

    while (!aristas_restantes.empty()) {
        int nodo_a_seleccionar = seleccionarNodoConMayorGrado(grado_incidencia, recubrimiento.nodos_seleccionados);
        if (nodo_a_seleccionar == -1) {
            // No se pudo encontrar un nodo no seleccionado con grado de incidencia positivo.
            // Esto indica que no se puede encontrar un recubrimiento válido.
            break;
        }

        // Agregar el nodo seleccionado al conjunto recubrimiento.
        recubrimiento.agregarNodo(nodo_a_seleccionar);

        // Eliminar todas las aristas incidentes en el nodo seleccionado de aristas_restantes.
        aristas_restantes.erase(
            std::remove_if(aristas_restantes.begin(), aristas_restantes.end(),
                [nodo_a_seleccionar](const Arista& arista) {
                    return arista.u == nodo_a_seleccionar || arista.v == nodo_a_seleccionar;
                }),
            aristas_restantes.end()
        );
    }

    return recubrimiento;
}

int main() {
    std::vector<Arista> grafo;
    agregarArista(grafo, 1, 2);
    agregarArista(grafo, 1, 3);
    agregarArista(grafo, 2, 3);
    agregarArista(grafo, 3, 4);
    agregarArista(grafo, 4, 5);

    int num_nodos = 5; // Se asume que los nodos están numerados desde 1 hasta num_nodos.

    Recubrimiento recubrimiento = obtenerRecubrimientoGreedy(grafo, num_nodos);

    std::cout << "Nodos en el recubrimiento: ";
    for (int nodo = 1; nodo <= num_nodos; ++nodo) {
        if (recubrimiento.nodos_seleccionados[nodo]) {
            std::cout << nodo << " ";
        }
    }
    std::cout << std::endl;

    return 0;
}


*/