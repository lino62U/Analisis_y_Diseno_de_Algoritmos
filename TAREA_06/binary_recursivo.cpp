#include <iostream>
#include <vector>

using namespace std;

int binarySearchRecursive(vector<int>& arr, int target, int left, int right) {
    if (left > right) {
        // El elemento no se encuentra en el vector
        return -1;
    }

    int mid = left + (right - left) / 2;

    if (arr[mid] == target) {
        // El elemento se encuentra en el índice mid
        return mid;
    } else if (arr[mid] > target) {
        // El elemento objetivo está en la mitad izquierda del vector
        return binarySearchRecursive(arr, target, left, mid - 1);
    } else {
        // El elemento objetivo está en la mitad derecha del vector
        return binarySearchRecursive(arr, target, mid + 1, right);
    }
}

int binarySearch(vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    return binarySearchRecursive(arr, target, left, right);
}

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int target = 11;

    int index = binarySearch(arr, target);

    if (index != -1) {
        cout << "El elemento " << target << " se encuentra en el índice " << index << endl;
    } else {
        cout << "El elemento " << target << " no se encuentra en el vector" << endl;
    }

    return 0;
}
