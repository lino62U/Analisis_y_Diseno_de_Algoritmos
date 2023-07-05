#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct Task {
   int b;
   int d;
};

bool comp(Task j1, Task j2) {
   return (j1.b > j2.b); 
}

int min(int a, int b) {
   return (a < b) ? a : b;
}

void taskAlgorithm( vector<Task> &candidatos, vector<Task*> &solucion)
{
    int n = candidatos.size();
   
    sort(candidatos.begin(), candidatos.end(), comp); 

    for (auto i : candidatos)
    {
        cout<<i.b<<" ";
    }
    cout<<endl;
    
  
    vector<bool> slot(n, false); 
   
    solucion.resize(n);

    for (Task c: candidatos) { 
        for (int j = min(n, c.d) - 1; j >= 0; j--) { 
            if (!slot[j]) {
                slot[j] = true; 
                solucion[j]= new Task{c.b,c.d};
                break;
            }
        }
    }
}

int main() {
    /*
    Beneficio gi: 50 10 15 30
    Plazo límite di: 2 1 2 1
    */
    vector<Task> candidatos = {{50,2},{10,1},{15,2},{30,1}};
    vector<Task*> solucion;
   
    taskAlgorithm(candidatos, solucion);
  
  
    cout<<"\nResultado: "<<endl;
    for(auto a: solucion)
        cout << a->b << " "<<a->d<<endl; 
   

   return 0;
}