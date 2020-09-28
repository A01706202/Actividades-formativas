/*--------------------
Michelle Aylin Calzada Montes
A01706202
Act 2.1
--------------------*/

#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <sstream>
#include <cstring>
#include <string>

using namespace std;



template <class T> class List;
template <class T> class ListIterator;

template <class T>
class Link {
private:
	Link(T);
	Link(T, Link<T>*);
	Link(const Link<T>&);

	T value;
	Link<T> *next;

	friend class List<T>;

};

template <class T>
Link<T>::Link(T val) : value(val), next(0) {}

template <class T>
Link<T>::Link(T val, Link* nxt) : value(val), next(nxt) {}

template <class T>
Link<T>::Link(const Link<T> &source) : value(source.value), next(source.next) {}


template <class T>
class List{
	public:
		string toString() const;
		List();
		List(const List<T>&);
		~List();
		bool empty() const;
		void add_first(T);
		void add(T);
		T find(T);
		void update(T,T);
		T remove(T);		
		
	private:
		Link<T> *head;
		int size;
};

template <class T>
string List<T>::toString() const {
	stringstream aux;
	Link<T> *p;

	p = head;
	aux << "[";
	while (p != 0) {
		aux << p->value;
		if (p->next != 0) {
			aux << ", ";
		}
		p = p->next;
	}
	aux << "]";
	return aux.str();
}

template <class T>
List<T>::List() : head(0), size(0) {}

template <class T>
List<T>::~List() {
}

template <class T>
bool List<T>::empty() const {
	return (head == 0);
}

template <class T>
void List<T>::add_first(T val) {
	Link<T> *newLink;
	
	newLink = new Link<T>(val);
	
	newLink->next = head;
	head = newLink;
	size++;
}

template <class T>
void List<T>::add(T val){
	Link<T> *newLink, *p;
	
	newLink = new Link<T>(val);
	if(empty()){
		add_first(val);
		return;
	}
	
	p = head;
	while (p->next != 0) {
		p = p->next;
	}
	
	newLink->next = 0;
	p->next = newLink;
	size++;
}

template <class T>
T List<T>::find(T val){
	int n = 0;
	Link<T> *p;
	
	p = head;
	while(p != 0){
		if (p->value == val){
			return n;
		}
		p = p->next;
		n++;
	}
	
	return -1;
}

template <class T>
void List<T>::update(T pos,T val){
    int i = 0;
	Link<T> *p;
	
	p = head;
	while (p != 0){
		if (i == pos){
			p->value = val;
		}
		p = p->next;
		i++;
	}
}

template <class T>
T List<T>::remove(T pos){
	int i = 0;
	Link<T> *p;
	
	p = head;
	while (p != 0){
		if (i == pos){
			delete *p;	
		}
		p = p->next;
		i++;
	}
	size--;
}

#endif
