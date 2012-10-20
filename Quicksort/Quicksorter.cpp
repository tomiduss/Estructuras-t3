#include "Quicksorter.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

Quicksorter::Quicksorter() {
	// TODO Auto-generated constructor stub

}

Quicksorter::~Quicksorter() {
	// TODO Auto-generated destructor stub
}

void Quicksorter::sort( int* arreglo, int length, int tipo){

	_array = arreglo;
	_size = length;
	quicksort( arreglo, 0, length - 1, tipo);
}


void Quicksorter::quicksort( int* arreglo, int min, int max, int tipo){

	if( max-min +1 <= 0)
	{
		return;
	}

	int indice_pivote = pivotear( arreglo, min, max, tipo);

	quicksort( arreglo, min, indice_pivote -1, tipo);
	quicksort( arreglo, indice_pivote + 1, max, tipo);

}

int Quicksorter::pivotear( int* arreglo, int min, int max, int tipo )
{

	int indice_pivote = elegirPivote( tipo, arreglo, min, max);

	//exchange( arreglo, indice_pivote, min);
	int temp = arreglo[indice_pivote];
	arreglo[ indice_pivote ] = arreglo[ min ];
	arreglo[ min ] = temp;


	int valor_pivote = arreglo[indice_pivote];

	//recorremos el arreglo buscando todos los numeros menores que el pivote
	for( int i = min + 1; i <= max; i++)
	{
		//si encontramos un numero menor que el pivote, lo intercambiamos de posicion
		if( arreglo[i] < valor_pivote)
		{
			indice_pivote++;
			exchange( arreglo, i, indice_pivote);
		}
	}

	//exchange( arreglo, min, indice_pivote);
	temp = arreglo[ min ];
	arreglo[ min ] = arreglo[ indice_pivote ];
	arreglo[ indice_pivote] = temp;


	//retorno el lugar donde quedo el pivote
	return indice_pivote;
}

int Quicksorter::elegirPivote( int tipo, int* arreglo, int min, int max){
	srand ( time(NULL) );

	if( tipo == 1)
		return min;
	else if (tipo == 2)
	{
		int ej = rand() % (max - min) + min;
		cout << min << max << ej << endl;
		return ej;
	}
	else
		return max;
}

//Este metodo recibe un arreglo y dos enteros e intercambia o valores del arreglo
//que se encuentran en esas posiciones.
void Quicksorter::exchange( int* a, int i, int j){

	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;

}

void Quicksorter::print(){
	cout << "[ " ;
	for(int i = 0; i < _size; i++){
		cout << _array[i] << ", ";
	}
	cout << " ]" << endl;
}




