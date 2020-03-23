#include "Tree.h"
#include <iostream>

using namespace std;

Tree::Tree() {
	// @author: Stefan
	head = nullptr;
	nr_node = 0;
}

Node* Tree::get_first(){
	// @author: Stefan
	return head;
}

bool Tree::insert(int val) {
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
		return true;
	}
	else { // if list is not empty 
		Node* index = head; // creating an index to go throw tree
		while (index->left != nullptr && index->right != nullptr) // i go through the tree until i find a free space 
		{
			if (new_node->value < index->value) // if new_node's value is lower that curent index value index become his left
				index = index->left;
			else // else index become his right
				index = index->right;
		}
		// if the free space is in the left of the index I add the new node there 
		if (index->left == nullptr && new_node->value < index->value) {
			index->left = new_node;
			nr_node++; // increasing nodes number;
			return true;
		} // else I add the node to the right of the index
		else {
			index->right = new_node;
			nr_node++; // increasing nodes number;
			return true;
		}
	}
	return false;
}

void Tree::find_min(Node* iterator, Node* start, Node* end, Node* &minim) {
	/*
	Goes throw the tree (using preorder) and looking for the smallest node value greater than node start value.
	Returns the minim throw minim parameter
	Input:
		iterator (Node*) - iterate throw the tree
		start (Node*) - lower edge
		end (Node*) - greater edge
		minim (Node*) - minimum between start and end node values 
	@author: Stefan
	*/
	if (iterator == NULL)
		return;
	if (iterator->value<end->value && iterator->value>start->value) { // checking if value is between bounds
		minim = iterator;
	}
	find_min(iterator->left, start, end, minim); // left side of the tree
	find_min(iterator->right, start, end, minim); // right side of the tree
}

bool Tree::delete_left(Node* index) {
	/*
	Deletes the node from index's left and change it with the smallest node greater than it
	Returns true if node was succesfuly changed and false if not;
	Input: 
		index (Node*) - reference position
	Output:
		bool
	@author: Stefan
	*/
	if (index->left->is_leaf() == true) { // if index left is a leaf just remove that node from tree
		index->left = nullptr;
		nr_node--;
		return true;
	}
	else if (index->left->sons() == 1) { // if index left has just one son that son takes his parent place in tree
		if (index->left->right != nullptr) { // if son is in the right of his parent (index->left)
			index->left = index->left->right; // son take his parent place in tree
			nr_node--; // decreasing node number
			return true;
		}
		else { // else son is in the left of his parent (index->left)
			index->left = index->left->left; // son take his parent place in tree
			nr_node--; // decreasing node number
			return true;
		}
	}
	else { // else index left has 2 sons and we are loking for the lowerst node greater than it
		Node* substitute = new Node; // creating a new node to stare the substitute of index left
		find_min(head, index->left, index, substitute); // finding the substitute of index left and return it via parameter substitute
		// index left sons become substitute's sons
		substitute->left = index->left->left; 
		substitute->right = index->left->right;

		// finding curent position of the substitute in tree and deleting it from there
		Node* kill = substitute;
		while (kill->left->value != substitute->value && kill->right->value != substitute->value)
		{
			if (substitute->value < kill->value)
				kill = kill->left;
			else
				kill = kill->right;
		}
		// deleting substitute from his curent position
		if (kill->right != nullptr && kill->right->value == substitute->value)
			kill->right = nullptr;
		if (kill->left != nullptr && kill->left->value == substitute->value)
			kill->left = nullptr;

		//moving substitute to index left position
		index->left = substitute;
		nr_node--; // decreasing nodes number
		return true;
	}
	return false;
}

bool Tree::delete_right(Node* index) {
	/*
	Deletes the node from index's right and change it with the smallest node greater than it
	Returns true if node was succesfuly changed and false if not;
	Input: 
		index (Node*) - reference position
	Output:
		bool
	@author: Stefan
	*/
	if (index->right->is_leaf() == true) { // if index right is a leaf just remove that node from tree
		index->right = nullptr;
		nr_node--;
		return true;
	}
	else if (index->right->sons() == 1) { // if index right has just one son that son takes his parent place in tree
		if (index->right->right != nullptr) { // if son is in the right of his parent (index->left)
			index->right = index->right->right; // son take his parent place in tree
			nr_node--; // decreasing node number
			return true;
		}
		else { // else son is in the left of his parent (index->left)
			index->right = index->right->left; // son take his parent place in tree
			nr_node--; // decreasing node number
			return true;
		}

	}
	else { // else index right has 2 sons and we are loking for the lowerst node greater than it
		Node* substitute = new Node; // creating a new node to stare the substitute of index right
		find_min(head, index, index->right, substitute); // finding the substitute of index right and return it via parameter substitute
		// index right sons become substitute's sons
		substitute->left = index->right->left;
		substitute->right = index->right->right;

		// finding curent position of the substitute in tree and deleting it from there
		Node* kill = substitute;
		while (kill->left->value != substitute->value && kill->right->value != substitute->value)
		{
			if (substitute->value < kill->value)
				kill = kill->left;
			else
				kill = kill->right;
		}
		// deleting substitute from his curent position
		if (kill->right != nullptr && kill->right->value == substitute->value)
			kill->right = nullptr;
		if (kill->left != nullptr && kill->left->value == substitute->value)
			kill->left = nullptr;

		//moving substitute to index right position
		index->right = substitute;
		nr_node--; // decreasing nodes number
		return true;
	}
	return false;
}



bool Tree::remove(int val) {
	/*
	Finding the node with value equal to val and remove it from tree
	Input: 
		val (int) - value searched
	Output:
		bool
	@author: Stefan
	*/
	 if (is_empty() == true) // if tree is empty return false
		 return false;

	 Node* index = head; // index become iterator and start from head

	 if (index->value == val) { // checking if head's value is equal with val
		 if (index->left != nullptr) { // head's left is not null it's left become head
			 head = head->left;
			 index = index->left;
			 nr_node--;
			 return true;
		 }
		 else { // else heads's right become head
			 head = head->right;
			 index = index->right;
			 nr_node--;
			 return true;
		 }
	 }

	 // i go through the tree until i find a node value equal to val 
	 while (index->left!=nullptr && index->right!=nullptr && index->left->value != val  && index->right->value != val)
	 {
		 if (val < index->value)
			 index = index->left;
		 else
			 index = index->right;
	 }
	 // if val is in the left node 
	 if (index->left != nullptr && index->left->value == val) {
		 return delete_left(index); // delete/change index left with another node
	 }
	 // if val is in the right node 
	 if (index->right != nullptr && index->right->value == val) {
		 return delete_right(index); // delete/change index right with another node
	 }
	 return false;
}

void Tree::preorder(Node* start, std::string& s){
	/*
	Goes through the tree using preorder rule and creating a string with nodes's values
	Returns string done via parameter s
	Input:
		start (Node*) - starting position of the traversal
		s (string) - value of the nodes in string format
	@author: Stefan
	*/
	if (start == NULL)
		return;
	s += std::to_string(start->value) + ", ";
	preorder(start->left, s);
	preorder(start->right, s);
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
	// @author: Stefan
	delete head;
}