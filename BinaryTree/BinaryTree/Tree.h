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

	void del(int val);

	int countNodes();

	bool is_empty();

	~Tree();
};

