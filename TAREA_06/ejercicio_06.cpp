/*
Para resolver el problema de asignación de tareas utilizando distintas estrategias greedy, consideraremos tres enfoques:

1. Greedy por el mínimo coste individual: En cada paso, asignaremos la tarea al trabajador que tenga el menor costo individual para esa tarea.

2. Greedy por el máximo coste individual: En cada paso, asignaremos la tarea al trabajador que tenga el mayor costo individual para esa tarea.

3. Greedy por el mínimo coste total: En cada paso, asignaremos la tarea al trabajador que tenga el menor costo total (considerando todas las tareas ya asignadas a ese trabajador).


En este código, hemos creado tres funciones que implementan las tres estrategias greedy para asignar tareas a trabajadores. El ejemplo proporcionado tiene 3 trabajadores y 3 tareas con costes asignados. Puedes modificar los valores de `n` y la matriz `costes` para probar con diferentes tamaños de entrada y observar cómo funcionan las diferentes estrategias greedy.
*/

#include <iostream>
#include <vector>
#include <algorithm>

struct Asignacion {
    int trabajador;
    int tarea;
    int costo;

    Asignacion(int t, int ta, int c) : trabajador(t), tarea(ta), costo(c) {}
};

bool compararMenorCosto(const Asignacion& a, const Asignacion& b) {
    return a.costo < b.costo;
}

bool compararMayorCosto(const Asignacion& a, const Asignacion& b) {
    return a.costo > b.costo;
}

int asignacionGreedyMinCostoIndividual(std::vector<std::vector<int>>& costes) {
    int n = costes.size();
    std::vector<Asignacion> asignaciones;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            asignaciones.emplace_back(i, j, costes[i][j]);
        }
    }

    std::sort(asignaciones.begin(), asignaciones.end(), compararMenorCosto);

    std::vector<bool> trabajador_asignado(n, false);
    std::vector<bool> tarea_asignada(n, false);
    int costo_total = 0;

    for (const Asignacion& asignacion : asignaciones) {
        if (!trabajador_asignado[asignacion.trabajador] && !tarea_asignada[asignacion.tarea]) {
            costo_total += asignacion.costo;
            trabajador_asignado[asignacion.trabajador] = true;
            tarea_asignada[asignacion.tarea] = true;
        }
    }

    return costo_total;
}

int asignacionGreedyMaxCostoIndividual(std::vector<std::vector<int>>& costes) {
    int n = costes.size();
    std::vector<Asignacion> asignaciones;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            asignaciones.emplace_back(i, j, costes[i][j]);
        }
    }

    std::sort(asignaciones.begin(), asignaciones.end(), compararMayorCosto);

    std::vector<bool> trabajador_asignado(n, false);
    std::vector<bool> tarea_asignada(n, false);
    int costo_total = 0;

    for (const Asignacion& asignacion : asignaciones) {
        if (!trabajador_asignado[asignacion.trabajador] && !tarea_asignada[asignacion.tarea]) {
            costo_total += asignacion.costo;
            trabajador_asignado[asignacion.trabajador] = true;
            tarea_asignada[asignacion.tarea] = true;
        }


    }

    return costo_total;
}

int asignacionGreedyMinCostoTotal(std::vector<std::vector<int>>& costes) {
    int n = costes.size();
    std::vector<Asignacion> asignaciones;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            asignaciones.emplace_back(i, j, costes[i][j]);
        }
    }

    std::sort(asignaciones.begin(), asignaciones.end(), compararMenorCosto);

    std::vector<bool> trabajador_asignado(n, false);
    int costo_total = 0;

    for (const Asignacion& asignacion : asignaciones) {
        if (!trabajador_asignado[asignacion.trabajador]) {
            costo_total += asignacion.costo;
            trabajador_asignado[asignacion.trabajador] = true;
        }
    }

    return costo_total;
}

int main() {
    int n = 3;
    std::vector<std::vector<int>> costes = {
        {2, 1, 3},
        {4, 2, 1},
        {3, 2, 5}
    };

    std::cout << "Costo total con asignación greedy por mínimo costo individual: "
              << asignacionGreedyMinCostoIndividual(costes) << std::endl;

    std::cout << "Costo total con asignación greedy por máximo costo individual: "
              << asignacionGreedyMaxCostoIndividual(costes) << std::endl;

    std::cout << "Costo total con asignación greedy por mínimo costo total: "
              << asignacionGreedyMinCostoTotal(costes) << std::endl;

    return 0;
}
