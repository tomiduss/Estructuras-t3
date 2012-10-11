/*
 * Node.h
 *
 *  Created on: Oct 3, 2012
 *      Author: tomas
 */

#ifndef NODE_H_
#define NODE_H_

class Node {
public:
	Node();
	Node(Node* n);

	virtual ~Node();

	friend class Heap;

private:

	Node* father;
	Node* left;
	Node* right;

	int value;

};

#endif /* NODE_H_ */
