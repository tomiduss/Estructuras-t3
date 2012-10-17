//============================================================================
// Name        : Heap.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Heap.h"
using namespace std;

int main() {

	int numeros [] = {12, 34, 2, 56, 87, 20, 867, 0 , 0, 0 };//, 98, 43, 23, 345 , 45 ,8 , 1};
	int numeros2 [] = {12, 34, 2, 56, 87, 20, 867, 98, 43, 23, 345 , 45 ,8 , 1};

	//heapsort
	cout << "Heapsort 1";

	Heap::heapsort(numeros, 7, 10);

	cout << "Heapsort 2";
	Heap::heapsort2(numeros2, 14, 14);

	return 0;
}
