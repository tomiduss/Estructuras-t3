/*
 * Heap.cpp
 *
 *  Created on: Oct 3, 2012
 *      Author: tomas
 */

#include <iostream>
#include "Heap.h"
#include <math.h>


Heap::Heap() {
	array = new int[10];
	count = 0;
	array_size = 10;
	for(int i = 0; i < array_size; i++){
		array[i] = 0;
	}
}
Heap::Heap(int* data, int data_size) {
	array = data;
	count = 0;
	array_size = data_size;
}

Heap::Heap(int* data, int n, int data_size){
	array = data;
	count = n;
	array_size = data_size;
	heapify();
}


Heap::~Heap() {
	delete [] array;
}

int Heap::size(){
	return count;
}
bool Heap::empty(){
	return count == 0 ;
}
void Heap::insert(int val){
	//Insertamos en la ultima posicion, llamamos a heapify.
	array[count] = val;
	if( count == array_size ){
		resize();
	}

	up_heap(count);
	count++;
}
int Heap::findMax(){
	return array[0];
}

void Heap::resize(){
	//copiar todos los elementos
	array_size = count*2;
	int* aux = new int [array_size];

	for(int i = 0; i < array_size; i++){
		if( i < count )
			aux[i] = array[i];
		else
			aux[i] = 0;
	}
	delete [] array;
	array = aux;
}

void Heap::up_heap(int i){
	if(i == 0)
		return;
	else if ( array[i] >= array[floor((i-1)/2)] )//Comparamos el valor con el padre, si es mayor, hacemos el swap, y aplicamos la recursion hacia arriba
	{
		int aux = array[i];
		array[i] = array[floor((i-1)/2)];
		array[floor((i-1)/2)] = aux;
		up_heap(floor((i-1)/2));
	}
	else
		return;
}

void Heap::removeMax(){
	//Swap con el ultimo
	cout << endl;
	cout << "BEGIN REMOVE MAX , count = " << size() <<endl;
	cout << "Max element en array[0]: " << array[0]<< endl << "Ultimo elemento en array[count-1]: " << array[count-1] << endl;
	cout << "estado array:  ";
	print();
	cout << endl;
	cout << endl;
	if( count == 1){
		array[0] = 0;
		count--;
		return;
	}
	else{
		cout << "SWAP" << endl;
		array[0] = array[count-1];
		array[count-1] = 0;
		cout << "array[0]: " << array[0] << " array[count-1]: " << array[count-1] << endl;
		count--;
		down_heap(0);

	}
	cout << endl;
	cout << endl;
	cout << "FINISH REMOVE MAX , count = " << size() << endl;
	cout << "Max element en array[0]: " << array[0]<< endl << "Ultimo elemento en array[count-1]: " << array[count-1] << endl;
	cout << "estado array:  ";
	print();
	cout << "---------------------------------------------------------------------"<< endl;
}

void Heap::down_heap(int i){
	cout << endl;
	cout << "DOWN HEAP. Index i: "<< i << endl;
	cout << "Count: " << count << endl;
	cout << "hijo izq: array[" << 2*i + 1 << "] = "<< array[2*i+1] <<  endl;
	cout << "hijo der: array[" << 2*i + 2 << "] = "<< array[2*i+2] <<  endl;

	cout << "array[i]: " << array[i] << endl;
	cout << endl;
	int left = -1; int right = -1;
	int li = 2*i + 1;
	int ri = 2*i + 2;

	if( ri <= count ){//Si tiene ambos hijos.
		right = array[ri];
		left = array[li];
		if( left >= right && array[i] <= left ){//Swap con el hijo izquierdo
			cout << "SWAP con hijo izquierdo"<<endl;
			int aux = left;
			array[li] = array[i];
			array[i] = aux;
			down_heap(li);
		}
		if(left < right &&  array[i] < right){//Swap con el hijo derecho
			cout << "SWAP con hijo derecho"<<endl;
			int aux = right;
			array[ri] = array[i];
			array[i] = right;
			down_heap(ri);
		}
	}
	else if( li <= count ){//Si el ultimo elemento es un hijo izquierdo
		left = array[li];
		if( array[i] <= left ){//Swap con el hijo izquierdo
			cout << "SWAP con hijo izquierdo"<<endl;
			int aux = left;
			array[li] = array[i];
			array[i] = aux;
			down_heap(li);
		}
	}
	else
		return;
}


int Heap::floor(double a){
	return (int)a;
}

void Heap::print(){
	cout << "[ " ;
	for(int i = 0; i < array_size; i++){
		cout << array[i];
		if( i == count-1)
			cout <<" | ";
		else if( i != array_size - 1)
			cout <<", ";
	}
	cout << " ]" << endl;
}

void Heap::heapsort(int* data, int n, int data_size){
	//Creamos nuevo heap con los elementos del arreglo.
	Heap* h = new Heap(data, data_size);
	//Insertar elementos al heap.
	for(int i = 0; i < n; i++){
		h->insert(data[i]);
		h->print();
	}
	//"Remover" los elementos
	for(int i = n; i > 0 ; i--){
		int aux = h->findMax();
		h->removeMax();
		//h->print();
		data[i-1] = aux;
		//h->print();
	}
	cout << "Final: ";
	h->print();
}

void Heap::heapsort2(int* data, int n, int data_size){
	Heap* h = new Heap(data, n, data_size);

	for(int i = n; i > 0 ; i--){
			int aux = h->findMax();
			h->removeMax();
			//h->print();
			data[i-1] = aux;
			//h->print();
		}
		cout << "Final: ";
		h->print();
}


void Heap::heapify(){
	double aux = (size - 1)/2;
	int n = floor(aux);
	for(int i = n; i > 0; i--){
		down_heap(i);
	}
}

