/*
 * Node.cpp
 *
 *  Created on: Oct 3, 2012
 *      Author: tomas
 */

#include "Node.h"

Node::Node() {
	father = 0;
	left = 0;
	right = 0;
}

Node::Node(Node* n){
	father = n->father;
	left = n->left;
	right = n->right;
}

Node::~Node() {
	// TODO Auto-generated destructor stub
}

