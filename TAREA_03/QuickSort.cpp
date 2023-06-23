// Quick sort in C++

#include <iostream>
using namespace std;

template <class N, class E, class S>
class Persona{
    public:
        N nombre;
        E edad;
        S estatura;
};

template <class T>
bool operator>=(const T a, const T b){
    if(a.edad%4==0 && b.edad%4!=0)
        return true;
    return false;
}

template <class T>
bool operator<=(const T a, const T b){
    if(a.nombre.length() >  b.nombre.length())
        return true;
    
    return false;
}
template <class T>
bool comparaEdad (T a, T b){
    return a >= b;
}
template <class T>
bool comparaNombres (T a, T b){
    return a<= b;
}
template <class T>
int partition(T *array, int low, int high, bool(*p)(T,T)) {
    
  T pivot = array[high];

  int i = (low - 1);

  for (int j = low; j < high; j++) {
    if (p(array[j],pivot)) {
      i++;
      T t= array[i];
      array[i]=array[j];
      array[j]=t;
    }
  }
  

  T t=array[i + 1];
  array[i + 1]=array[high];
  array[high]=t;

  return (i + 1);
}

template <class T>
void quickSort(T *array, int low, int high, bool(*p)(T,T)) {
  if (low < high) {

    int pi = partition(array, low, high,p);

    quickSort(array, low, pi - 1,p);

    quickSort(array, pi + 1, high,p);
  }
}
template <class K>
void mostrarClase(K *ptr, int n){
    cout<<"\n\t...TABLA..."<<endl;
    cout<<"N° \tEdad \tEstatura \tNombre"<<endl;
    for (int i = 0; i < n; i++){
        cout<<i+1<<"\t"<<ptr[i].edad<<"\t"<<ptr[i].estatura<<"\t\t"<<ptr[i].nombre<<endl;
    }
}

int main() {
    string names[]={"Leonidas","Aldo","Jose","Pedro"};
    int edades[]={ 23, 18, 32, 20};
    float esta[]={ 1.74, 1.83, 1.62, 1.74}; 

    Persona <string,int, float> *arar = new Persona<string,int, float>[4];
    Persona <string,int, float> *ptr = new Persona<string,int, float>[4];    
    /*
    for (int i = 0; i < 4; i++){
        arar[i].nombre = names[i];
        arar[i].edad = edades[i];
        arar[i].estatura = esta[i];
    }*/
    for (int i = 0; i < 4; i++){
        ptr[i].nombre = names[i];
        ptr[i].edad = edades[i];
        ptr[i].estatura = esta[i];
    }
    
	cout << "Given array is \n";
	mostrarClase(ptr,4);

  
  // perform quicksort on data
  quickSort(ptr, 0, 3,comparaNombres);
  
  cout << "Sorted array in ascending order: \n";
	mostrarClase(ptr,4);
  
}
