#pragma once
#include "Node.h"
class Tree
{
private:
	Node* head;
	int nr_node;
public:
	Tree();

	void insert(int val);

	void remove(int val);

//	Node* find_min(Node* iterator, Node* start, Node* end);

	int countNodes();

	bool is_empty();

	~Tree();
};

