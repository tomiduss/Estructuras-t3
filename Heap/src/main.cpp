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

	//heapsort
	Heap::heapsort(numeros, 7, 10);

	return 0;
}
