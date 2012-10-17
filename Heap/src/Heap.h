/*
 * Heap.h
 *
 *  Created on: Oct 3, 2012
 *      Author: tomas
 */

#ifndef HEAP_H_
#define HEAP_H_
using namespace std;

class Heap {
public:
	Heap();
	Heap(int* data, int data_size);//para heapsort
	Heap(int* data, int n, int data_size);
	virtual ~Heap();

	int size();
	bool empty();
	void insert(int val);
	int findMax();
	void removeMax();
	void print();
	static void heapsort(int* , int, int);
	static void heapsort2(int* , int, int);

private:
	int* array;
	int count;
	int array_size;

	void heapify();
	void up_heap(int i);
	void down_heap(int i);
	void resize();
	int floor(double a);
};

#endif /* HEAP_H_ */
