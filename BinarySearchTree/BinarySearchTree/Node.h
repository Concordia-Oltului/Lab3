#pragma once
class Node
{
public:
	int value;
	Node* left;
	Node* right;

	Node();

	Node(int val);

	int get_value();

	bool is_leaf();

	int sons();

	~Node();



};

