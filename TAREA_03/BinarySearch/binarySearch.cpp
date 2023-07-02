#include <iostream>
#include <vector>

using namespace std;

int binarySearch(const vector<int>& candidatos, int n) {
    int left = 0;
    int right = candidatos.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (candidatos[mid] == n) {
            return mid;
        } else if (candidatos[mid] < n) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1; // Elemento no encontrado
}

int main() {
    vector<int> candidatos = {1, 3, 5, 7, 9, 11, 13, 15};
    cout<<"Candidatos: "<<endl;
    for (auto i: candidatos)
    {
        cout<<i<<" ";
    }
        
    
    int n = 7;
  

    int index = binarySearch(candidatos, n);


    if (index != -1) {
        cout << "\nEl número " << n << " se encuentra en la posición " << index << endl;
    } else {
        cout << "\nEl número " << n << " no se encuentra en la lista." << endl;
    }

    return 0;
}
