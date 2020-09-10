/*---------------
Michelle Aylin Calzada Montes
A01706202
Act 1.2 Algoritmos de Búsqueda y Ordenamiento
---------------*/

#ifndef SORTS_H_
#define SORTS_H_
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cstring>
#include <string>

using namespace std;

template <class T>
class Sorts {
	private:
		void swap(vector<T>&, int i, int j);
		void copyArray(vector<T> &a, vector<T> &b, int menor, int mayor);
    	void mergeArray(vector<T> &a, vector<T> &b, int menor, int mitad, int mayor);
	    void mergeSplit(vector<T> &a, vector<T> &b, int menor, int mayor);
		
	public:
		vector<T> ordenaSeleccion(const vector<T> &b);
		vector<T> ordenaBurbuja(const vector<T> &b);
		vector<T> ordenaMerge(const vector<T> &b);
		int busqSecuencial(const vector<T> &b, int v);	
		int busqBinaria(const vector<T> &b, int v);
};

template <class T>
void Sorts<T>::swap(vector<T> &v, int i, int j) {
	T aux = v[i];
	v[i] = v[j];
	v[j] = aux;
}

template <class T>
void Sorts<T>::copyArray(vector<T> &a, vector<T> &b, int menor, int mayor) {
	for (int i = menor; i <= mayor; i++) {
		a[i] = b[i];
	}
}

template <class T>
void Sorts<T>::mergeArray(vector<T> &a, vector<T> &b, int menor, int mitad, int mayor) {
	int i, j, l;

	i = menor;
	j = mitad + 1;
	l = menor;

	while (i <= mitad && j <= mayor) {
		if (a[i] < a[j]) {
			b[l] = a[i];
			i++;
		} else {
			b[l] = a[j];
			j++;
		}
		l++;
	}
	if (i > mitad) {
		for (; j <= mayor; j++) {
			b[l++] = a[j];
		}
	} else {
		for (; i <= mitad; i++) {
			b[l++]=a[i];
		}
	}
}

template <class T>
vector<T> Sorts<T>::ordenaSeleccion(const vector<T> &b) {
	vector<T> a(b);
	int posicion;

	for (int i = a.size() - 1; i > 0; i--) {
		posicion = 0;
		for (int j = 1; j <= i; j++) {
			if (a[j] > a[posicion]) {
				posicion = j;
			}
		}
		if (posicion!=i) {
			swap(a, i, posicion);
		}
	}
	return a;
}

template <class T>
vector<T> Sorts<T>::ordenaBurbuja(const vector<T> &b){
	vector<T> a(b);
	for(int i = a.size() - 1; i > 0; i--){
		for (int j = 0; j < i; j++) {
			if (a[j] > a[j + 1]) {
				swap(a, j, j + 1);
			}
		}
	}
	return a;
}

template <class T>
int Sorts<T>::busqSecuencial(const vector<T> &b , int v){
    vector<T> k(b);
    int tam = k.size();
	for (int i = 0; i < tam; i++) {
		if (v == b[i]) {
			return b[i];
		}
	}
	return -1;
}

template <class T>
int Sorts<T>::busqBinaria(const vector<T> &b, int v){
    vector<T> i(b);
    int tam = i.size();
	int mitad;
	int menor = 0;
	int mayor = tam - 1;

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
