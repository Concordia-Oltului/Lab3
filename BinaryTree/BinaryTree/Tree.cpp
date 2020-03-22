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
		Node* index = head; // creating an node to iterate in tree
		if (countNodes() > 2) { // if tree has more than 2 nodes is searching for a node which has 1 or 0 sons
			while (index->left==nullptr || index->right==nullptr)
			{
				if (index->left->left != nullptr || index->left->right != nullptr)
					index = index->left;
				else if (index->right->left != nullptr || index->right->left != nullptr)
					index = index->right;
				else
					index = index->left;
			}
		}
		if (index->left == nullptr) { // if left pozistion is empty adding new_node to that position
			index->left = new_node;
			nr_node++;
		}
		else if (index->left->value > new_node->value) { // if node's value from left position is greater that new_node's value
			index->right = index->left; // moving node from left position to right position and
			index->left = new_node; // adding new_node to left position
			nr_node++;
		}
		else {
			index->right = new_node; // if node's value from left position is lower that new_node's value adding new_node to right position
			nr_node++;
		}


	}


}

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