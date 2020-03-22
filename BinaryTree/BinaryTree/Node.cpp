#include "Node.h"
#include <iostream>

Node::Node()
{
	value = NULL;
	left = nullptr;
	right = nullptr;
}

Node::Node(int val) {
	value = val;
	left = nullptr;
	right = nullptr;
}

int Node::get_value()
{
	return value;
}

bool Node::is_leaf() {
	/*
	Verifing that node is a leaf in the tree (has no sons)
	Input:
		-
	Output:
		bool

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
	delete left;
	delete right;
}