#include "Tree.h"
#include <iostream>

using namespace std;

Tree::Tree() {
	head = nullptr;
	nr_node = 0;
}

void Tree::insert(int val) {
	/*
	Insert a new node in tree
	Input:
		val - int 
	Output:
		 - 
	@author: Stefan
	*/
	
	//creating a new node and atribute val to it
	Node* new_node = new Node;
	new_node->value = val;

	if (head == nullptr) {// if list is empty the new node become head
		head = new_node;
		nr_node++;
	}
	else {
		Node* index = head;
		while (index->left != nullptr && index->right != nullptr)
		{
			if (new_node->value < index->value)
				index = index->left;
			else
				index = index->right;
		}
		if (index->left == nullptr && new_node->value < index->value)
			index->left = new_node;
		else
			index->right = new_node;
	}
}
/*
Node* Tree::find_min(Node* iterator, Node* start, Node* end) {
	if (iterator == nullptr)
		return end;
	if (iterator->value<end->value && iterator->value>start->value) {
		end = iterator;
	}
	find_min(iterator->left, start, end);
	find_min(iterator->left, start, end);
}
*/

	/*
void Tree::remove(int val) {
	Node* index = head;
	 while (index->left->value != val  || index->right->value != val)
	 {
		 if (val < index->value)
			 index = index->left;
		 else
			 index = index->right;
	 }
	 if (index->left->value == val) {
		 if (index->left->is_leaf() == true) {
			 Node* killer = index->left;
			 index->left = nullptr;
			 delete killer;
		 }
		 else {
			 Node* aux = find_min(head, index->left->left, index->left->right);
		 }
	 }
	 if (index->right->value == val) {
		 Node* killer = index->right;
		 index->right = nullptr;
		 delete killer;
	 }

}

	*/
int Tree::countNodes() {
	/*
	Returning number of nodes from tree
	Input:
		-
	Output
		int
	@author: Stefan
	*/
	return nr_node;
}

bool Tree::is_empty() {
	/*
	Returning true if tree is empty and false if not
	Input:
		-
	Output
		bool 
	@author: Stefan
	*/
	if (head == nullptr)
		return true;
	return false;
}

Tree::~Tree() {
	delete head;
}