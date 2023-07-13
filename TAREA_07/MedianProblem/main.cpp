// Quick sort in C++

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

/*
    1
    1 2 3
    0 1 2 3 4
*/

long find_Media(vector<long>&vec)
{
    int size = vec.size();
    if(size%2!=0)
        return floor(vec[size/2]);
    
    int medio = size/2;
    medio--;
    return floor(( vec[medio] + vec[medio+1])/2);
        

}
int main() {

    vector<long> entradas;
    int size = 10000;
  
  // perform quicksort on data
  
    int X;
    while (cin>>X)
    {
        entradas.push_back(X);
        std::sort(entradas.begin(), entradas.end());
        //quickSort(entradas, 0, entradas.size()-1,comparaEdad);
        cout<<find_Media(entradas)<<endl;
        /* code */
    }
        
  
}
