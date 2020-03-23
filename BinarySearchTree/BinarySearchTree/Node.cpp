#include "Node.h"
#include <iostream>

Node::Node(){
	// @author: Stefan
	value = NULL;
	left = nullptr;
	right = nullptr;
}

Node::Node(int val) {
	// @author: Stefan
	value = val;
	left = nullptr;
	right = nullptr;
}

int Node::get_value(){
	// @author: Stefan
	return value;
}

bool Node::is_leaf() {
	/*
	Verifing that node is a leaf in the tree (has no sons)
	Input:
		-
	Output:
		bool
	@author: Stefan
	*/

	if (left == nullptr && right == nullptr)
		return true;
	return false;
}

int Node::sons() {
	/*
	Returns number of sons of a node
	Input:
		-
	Output:
		int
	@author: Stefan
	*/
	if (left == nullptr && right == nullptr)
		return 0;
	else
	{
		if (left == nullptr || right == nullptr)
			return 1;
		return 2;
	}
}

Node::~Node() {
	// @author: Stefan
	delete left;
	delete right;
}