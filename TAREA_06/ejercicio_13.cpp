// El algoritmo greedy para minimizar el número de fallos de caché se puede diseñar utilizando la estrategia "Least Recently Used" (LRU), que consiste en reemplazar el dato menos recientemente utilizado en la caché en caso de un fallo.

// **Algoritmo Greedy con estrategia LRU:**
// 1. Inicializar una caché vacía y una lista para llevar un seguimiento del orden de acceso a los datos almacenados en la caché.
// 2. Recorrer las solicitudes d1, d2, ..., dm en orden:
//    a. Si el dato di está en la caché (hit), actualizar su posición en la lista a la más reciente.
//    b. Si el dato di no está en la caché (miss), agregarlo a la caché y eliminar el dato menos recientemente utilizado de la lista.
// 3. El número de fallos de caché será igual al número de veces que se produjo un miss.

// **Código del Algoritmo Greedy con estrategia LRU:**

// ```cpp
#include <iostream>
#include <unordered_map>
#include <list>

class LRUCache {
private:
    int capacity;
    std::unordered_map<int, int> cacheMap;
    std::list<int> accessList;

public:
    LRUCache(int cap) {
        capacity = cap;
    }

    void update(int data) {
        auto it = accessList.begin();
        while (*it != data) {
            it++;
        }
        accessList.erase(it);
        accessList.push_front(data);
    }

    int cache(int data) {
        if (cacheMap.find(data) != cacheMap.end()) {
            update(data);
            return 1; // Hit
        }

        if (cacheMap.size() >= capacity) {
            int lastData = accessList.back();
            accessList.pop_back();
            cacheMap.erase(lastData);
        }

        cacheMap[data] = 1;
        accessList.push_front(data);
        return 0; // Miss
    }
};

int main() {
    // Ejemplo de conjunto de solicitudes
    std::vector<int> requests = {1, 2, 3, 1, 4, 2, 5, 6};

    int cacheCapacity = 3;
    LRUCache cache(cacheCapacity);
    int numMisses = 0;

    for (int request : requests) {
        numMisses += cache.cache(request);
    }

    std::cout << "Número de fallos de caché: " << numMisses << std::endl;

    return 0;
}
