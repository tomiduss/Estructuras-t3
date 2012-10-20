/*
 * main.cpp
 *
 *  Created on: 17-10-2012
 *      Author: nicolas
 */

#include <iostream>
#include "Quicksorter.h"

using namespace std;

int main(){

	int numeros [] = {12, 34, 2, 56, 87, 20, 867}; //, 98, 43, 23, 345 , 45 ,8 , 1};

	Quicksorter* sorter = new Quicksorter( );

	sorter->sort( numeros, 7, 2);
	sorter->print();
	cout << "fin";
	return 0;
}




