/*
 * Quicksorter.h
 *
 *  Created on: 17-10-2012
 *      Author: nicolas
 */

#ifndef QUICKSORTER_H_
#define QUICKSORTER_H_

class Quicksorter {
public:
	Quicksorter();
	//Quicksorter( int* array , int size);
	virtual ~Quicksorter();



	void sort( int* data, int lenght, int tipo);

	void print();

private:
	int* _array;
	int _size;

	int elegirPivote( int tipo, int* arreglo, int min, int max);
	int pivotear( int* arreglo, int min, int max, int tipo);
	void exchange(int* a, int i, int j);
	void quicksort( int* data, int min, int max, int tipo);

};

#endif /* QUICKSORTER_H_ */
