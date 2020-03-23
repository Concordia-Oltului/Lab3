#pragma once
#include "Node.h"
#include <string>

class Tree
{
private:
	Node* head;
	int nr_node;

	void find_min(Node* iterator, Node* start, Node* end, Node*& minim);
	bool delete_left(Node* index);
	bool delete_right(Node* index);

public:
	Tree();

	Node* get_first();

	bool insert(int val);

	bool remove(int val);

	void preorder(Node* start, std::string& s);

	int countNodes();

	bool is_empty();

	~Tree();
};

