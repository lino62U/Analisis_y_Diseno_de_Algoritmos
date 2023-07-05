/*
Para diseñar el algoritmo greedy que maximice las ganancias del camarero, podemos ordenar a los clientes en función de la propina que recibiría el camarero por atender a cada cliente. Luego, el camarero debe atender primero a los clientes que le proporcionen la mayor propina por minuto de espera.

Aquí está el algoritmo en pseudocódigo:

1. Crear una lista de tuplas (cliente, tiempo) que representen a cada cliente y su tiempo de atención respectivamente.
2. Calcular la propina para cada cliente (propina = 1 / tiempo) y almacenarla junto con el cliente y el tiempo en la lista de tuplas.
3. Ordenar la lista de tuplas en orden descendente según la propina.
4. Inicializar una variable "ganancias" en 0 para llevar un registro de las ganancias acumuladas del camarero.
5. Inicializar una variable "tiempo_actual" en 0 para llevar un registro del tiempo actual transcurrido.
6. Recorrer la lista de tuplas en el orden de la propina y, por cada cliente, sumar su propina a las ganancias del camarero y actualizar el "tiempo_actual" sumando el tiempo de atención del cliente.
7. Repetir el paso 6 para cada cliente de la lista.

Vamos a demostrar que este algoritmo greedy siempre devuelve la solución óptima. Para ello, usaremos el método de intercambio.

Supongamos que hay una solución óptima diferente a la solución proporcionada por el algoritmo greedy, en la que el camarero atiende a los clientes en un orden diferente. Sea S1 la solución óptima y S2 la solución proporcionada por el algoritmo greedy.

Podemos intercambiar un cliente C1 atendido en S1 con un cliente C2 atendido en S2, de manera que C1 sea atendido en S2 y C2 sea atendido en S1. Esto no cambiará el tiempo total de atención del camarero, ya que el tiempo de atención de C1 y C2 es el mismo en ambas soluciones. Sin embargo, puede afectar las ganancias del camarero.

Dado que la lista de clientes está ordenada en orden descendente según la propina, si intercambiamos C1 y C2, C1 debe tener una propina más alta que C2, es decir, p1 > p2. Además, el tiempo de atención de C1 es igual al tiempo de atención de C2, por lo que su propina por minuto de espera (p1 / t1) debe ser mayor que la propina por minuto de espera de C2 (p2 / t2).

Como hemos intercambiado a favor de un cliente con una mayor propina por minuto de espera, las ganancias del camarero deberían aumentar en este intercambio. Esto significa que S1 no era óptimo en primer lugar, lo cual es una contradicción.

Por lo tanto, no es posible encontrar una solución óptima diferente a la proporcionada por el algoritmo greedy. El algoritmo greedy siempre devuelve la solución óptima para maximizar las ganancias del camarero en este caso.
*/

#include <iostream>
#include <vector>
#include <algorithm>

struct Cliente {
    int id;
    int tiempo;
    double propina;

    bool operator>(const Cliente& other) const {
        return propina > other.propina;
    }
};

// Función para obtener las ganancias totales del camarero dado el orden de atención de los clientes.
double obtenerGanancias(const std::vector<Cliente>& clientes_atendidos) {
    double ganancias = 0.0;
    int tiempo_actual = 0;

    for (const Cliente& cliente : clientes_atendidos) {
        tiempo_actual += cliente.tiempo;
        ganancias += cliente.propina;
    }

    return ganancias;
}

// Algoritmo greedy para maximizar las ganancias del camarero.
std::vector<Cliente> maximizarGanancias(std::vector<Cliente>& clientes) {
    std::sort(clientes.begin(), clientes.end(), std::greater<Cliente>());

    return clientes;
}

int main() {
    int n;
    std::cout << "Ingrese el número de clientes: ";
    std::cin >> n;

    std::vector<Cliente> clientes(n);

    for (int i = 0; i < n; ++i) {
        std::cout << "Ingrese el tiempo de atención del cliente " << i + 1 << ": ";
        std::cin >> clientes[i].tiempo;
        clientes[i].propina = 1.0 / clientes[i].tiempo;
        clientes[i].id = i + 1;
    }

    std::vector<Cliente> orden_atencion = maximizarGanancias(clientes);
    double ganancias_totales = obtenerGanancias(orden_atencion);

    std::cout << "El orden óptimo de atención de los clientes es: ";
    for (const Cliente& cliente : orden_atencion) {
        std::cout << cliente.id << " ";
    }

    std::cout << "\nGanancias totales del camarero: " << ganancias_totales << std::endl;

    return 0;
}
