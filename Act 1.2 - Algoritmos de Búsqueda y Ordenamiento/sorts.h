/*---------------
Michelle Aylin Calzada Montes
A01706202
Act 1.2 Algoritmos de Búsqueda y Ordenamiento
---------------*/

#ifndef SORTS_H_
#define SORTS_H_

#include <vector>
#include <list>

using namespace std;

template <class T>
class Sorts {
	private:
		void swap(vector<T>&, int, int);
		void copyArray(vector<T>&, vector<T>&, int, int);
		void mergeArray(vector<T>&, vector<T>&, int, int, int);
		void mergeSplit(vector<T>&, vector<T>&, int, int);

	public:
		vector<T> ordenaSeleccion(vector<T>&);
    		vector<T> ordenaBurbuja(vector<T>&);
		vector<T> ordenaMerge(vector<T>&);
		int busqSecuencial(vector<T>&, int);
		int busqBinaria(vector<T>&, int);
};


template <class T>
void Sorts<T>::swap(vector<T> &b, int i, int j) {
	T aux = b[i];
	b[i] = b[j];
	b[j] = aux;
}

template <class T>
vector<T> Sorts<T>::ordenaSeleccion(vector<T> &b) {
    int pos;
    for (int i = 0; i < b.size(); i++) {
        pos = i;
		for (int j = i + 1; j < b.size(); j++) {
			if (b[j] < b[pos]) {
				pos = j;
			}
		}
        if(pos != i){
            swap(b, i, pos);
        }
	}
	return b;
}

template <class T>
vector<T> Sorts<T>::ordenaBurbuja(vector<T> &b) {
	int pos;
    for (int i = 0; i < b.size(); i++) {
        pos = i;
		for (int j = i + 1; j < b.size(); j++) {
			if (b[j] < b[pos]){
				pos = j;
			}
		}
        if(pos != i){
    		swap(b, i, pos);
    	}
	}
	return b;
}

template <class T>
vector<T> Sorts<T>:: ordenaMerge(vector<T> &b) {
	int pos;
   	for (int i = 0; i < b.size(); i++) {
    		pos = i;
		for (int j = i + 1; j < b.size(); j++) {
			if (b[j] < b[pos]){
				pos = j;
			}
		}
    if(pos != i){
    	swap(b, i, pos);
    	}
	}
	return b;
}

template <class T>
int Sorts<T>::busqSecuencial(vector<T> &b , int v){
	for (int i = 0; i < b.size(); i++) {
		if (v == b[i]) {
			return i;
		}
	}
	return -1;
}

template <class T>
int Sorts<T>::busqBinaria(vector<T> &b, int v){
	int mitad;
	int menor = 0;
	int mayor = b.size() - 1;

	while (menor < mayor) {
		mitad = (mayor + menor) / 2;
		if (v == b[mitad]) 
			return mitad;
		else if (v < b[mitad]) 
			mayor = mitad - 1;
	    else if (v > b[mitad]) 
			menor = mitad + 1;
	}
	return menor;
}

#endif
