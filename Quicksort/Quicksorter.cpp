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

	//Chequeamos que el arreglo tenga al menos tamaño 1. De lo contrario terminamos
	if( max-min  < 0 )
	{
		return;
	}

	//Pivoteamos el arreglo.
	int indice_pivote = pivotear( arreglo, min, max, tipo);

	//Aplicamos la recursion para los arreglosa los lados del pivote
	quicksort( arreglo, min, indice_pivote -1, tipo);
	quicksort( arreglo, indice_pivote + 1, max, tipo);

}

int Quicksorter::pivotear( int* arreglo, int min, int max, int tipo )
{
	//Si el arreglo tiene tamaño 1 retornamos.
	if(min == max)
		return min;

	//Primero elegimos el pivote, de alguna de las posibles maneras
	int indice_pivote = elegirPivote( tipo, arreglo, min, max);

	//Se intercambia el pivote con el primer elemento del arreglo
	exchange( arreglo, indice_pivote, min);

	//Partimos asumiendo que el pivote es el menor del arreglo
	indice_pivote = min;
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

	//Intercambio el pivote (que esta guardado en min), con el numero en la posicion del indice.
	exchange( arreglo, min, indice_pivote);

	//retorno el lugar donde quedo el pivote
	return indice_pivote;
}

//este metodo recibe un entero llamado tipo que define de cual de las tres formas
//se elige el pivote del arreglo.
int Quicksorter::elegirPivote( int tipo, int* a, int min, int max){
	srand ( time(NULL) );

	if( tipo == 1)
		return min;
	else if (tipo == 2)
		return ej = rand() % (max - min) + min;
	else
	{
		//calculamos el numero del medio del arreglo (truncado)
		int med = (( max - min)/2) + min;

		//retornamos el numero intermedio entre min, med y max
		if( a[min] <= a[med] && a[med] <= a[max])
			return med;
		else if ( a[med] <= a[max] && a[max] <= a[min])
			return max;
		else
			return min;
	}
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




