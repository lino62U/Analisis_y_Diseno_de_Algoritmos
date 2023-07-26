#include <iostream>
#include <vector>
using namespace std;

void knapsackDyProg(vector<int>& W, vector<int>& V, int M, int n) {
    vector<vector<int>> B(n + 1, vector<int>(M + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= M; j++) {
            B[i][j] = B[i - 1][j];

            if ((j >= W[i - 1]) && (B[i][j] < B[i - 1][j - W[i - 1]] + V[i - 1])) {
                B[i][j] = B[i - 1][j - W[i - 1]] + V[i - 1];
            }

            cout << B[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Max Value:\t" << B[n][M] << endl;

    cout << "Selected Packs: " << endl;

    while (n != 0) {
        if (B[n][M] != B[n - 1][M]) {
            cout << "\tPackage " << n << " with W = " << W[n - 1] << " and Value = " << V[n - 1] << endl;

            M = M - W[n - 1];
        }

        n--;
    }
}

int main() {
    vector<int> W = {2, 3, 4, 5};
    vector<int> V = {1, 2, 3, 4};
    int M = 7;
    int n = W.size();
    
    knapsackDyProg(W, V, M, n);
    
    return 0;
}
