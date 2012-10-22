/*
 * main.cpp
 *
 *  Created on: 17-10-2012
 *      Author: nicolas
 */

#include <iostream>
#include "Quicksorter.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main(){

	int numeros[10000]; //= {12, 34, 2, 56, 87, 20, 867, 98, 43, 23, 345 , 45 ,8 , 1};

	srand ( time(NULL) );

	for( int i = 0; i < 10000; i++)
	{
		numeros[i] = rand() % 1000000;
	}


	Quicksorter* sorter = new Quicksorter( );

	sorter->sort( numeros, 10000, 3);
	sorter->print();
	cout << "fin";
	return 0;
}




