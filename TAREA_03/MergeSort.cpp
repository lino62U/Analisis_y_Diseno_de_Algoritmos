// C++ program for Merge Sort
#include <iostream>
using namespace std;

template <class N,class E,class S>
class Persona{
    public:
        N nombre;
        E edad;
        S estatura;
};

template <class N,class E,class S>
class Estudiante: public Persona<N,E,S>{
    public:
        string cursos;
};

template <class T>
bool compareMayorClase(T x, T y, string t){
    if(t=="edad")
        return x.edad >= y.edad;
    else if(t=="estatura")
        return x.estatura >= y.estatura;
    else
        return x.nombre >= y.nombre;
}
template <class T>
bool compareMenorClase(T x, T y, string t){
    if(t=="edad")
        return x.edad <= y.edad;
    else if(t=="estatura")
        return x.estatura <= y.estatura;
    else
        return x.nombre <= y.nombre;
}


template <class G>
void merge(G *array, int const left, int const mid, int const right, bool (*p)(G,G,string),string aux)
{
	auto const subArrayOne = mid - left + 1;
	auto const subArrayTwo = right - mid;

	// Create temp arrays
	G *leftArray = new G[subArrayOne], *rightArray = new G[subArrayTwo];


	for (auto i = 0; i < subArrayOne; i++)
		leftArray[i] = array[left + i];
	for (auto j = 0; j < subArrayTwo; j++)
		rightArray[j] = array[mid + 1 + j];

	auto indexOfSubArrayOne = 0, // Initial index of first sub-array
		indexOfSubArrayTwo = 0; // Initial index of second sub-array
	int indexOfMergedArray = left; // Initial index of merged array


	while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
		if ( p(leftArray[indexOfSubArrayOne],rightArray[indexOfSubArrayTwo],aux)) {             //PUNTERO 
			array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
			indexOfSubArrayOne++;
		}
		else {
			array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
			indexOfSubArrayTwo++;
		}
		indexOfMergedArray++;
	}

	while (indexOfSubArrayOne < subArrayOne) {
		array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
		indexOfSubArrayOne++;
		indexOfMergedArray++;
	}

	while (indexOfSubArrayTwo < subArrayTwo) {
		array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
		indexOfSubArrayTwo++;
		indexOfMergedArray++;
	}
}



template <class P>
void mergeSort(P *array, int const begin, int const end,bool (*p)(P,P,string), string aux)
{
	if (begin >= end)
		return; // Returns recursively

	auto mid = begin + (end - begin) / 2;
	mergeSort(array, begin, mid, p, aux);
	mergeSort(array, mid + 1, end,p,aux);
	merge(array, begin, mid, end,p,aux);
}



// Driver code
template <class K>
void mostrarClase(K *ptr, int n){
    cout<<"\n\t...TABLA..."<<endl;
    cout<<"N° \tEdad \tEstatura \tNombre"<<endl;
    for (int i = 0; i < n; i++){
        cout<<i+1<<"\t"<<ptr[i].edad<<"\t"<<ptr[i].estatura<<"\t\t"<<ptr[i].nombre<<endl;
    }
}

int main()
{
	
    string names[]={"Leonidas","Aldo","Jose","Pedro"};
    int edades[]={ 23, 18, 32, 20};
    float esta[]={ 1.74, 1.83, 1.62, 1.74}; 

    Persona<string,int, float> *arar = new Persona<string,int, float>[4];
    Persona<string,int, float> *ptr = new Persona<string,int, float>[4];    
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

	mergeSort(ptr, 0, 3,compareMayorClase,"estatura");

	cout << "\nSorted array is \n";
	mostrarClase(ptr,4);
	
	return 0;
}

