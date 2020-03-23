#include "Tree.h"
#include <iostream>

using namespace std;

Tree::Tree() {
	head = nullptr;
	nr_node = 0;
}

Node* Tree::get_first()
{
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
	else {
		Node* index = head;
		while (index->left != nullptr && index->right != nullptr)
		{
			if (new_node->value < index->value)
				index = index->left;
			else
				index = index->right;
		}
		if (index->left == nullptr && new_node->value < index->value) {
			index->left = new_node;
			nr_node++;
			return true;
		}
		else {
			index->right = new_node;
			nr_node++;
			return true;
		}
	}
	return false;
}

void Tree::find_min(Node* iterator, Node* start, Node* end, Node* &minim) {
	if (iterator == NULL)
		return;
	if (iterator->value<end->value && iterator->value>start->value) {
		minim = iterator;
	}
	find_min(iterator->left, start, end, minim);
	find_min(iterator->right, start, end, minim);
}

bool Tree::delete_left(Node* index) {
	if (index->left->is_leaf() == true) {
		index->left = nullptr;
		nr_node--;
		return true;
	}
	else if (index->left->sons() == 1) {
		if (index->left->right != nullptr) {
			index->left = index->left->right;
			nr_node--;
			return true;
		}
		else {
			index->left = index->left->left;
			nr_node--;
			return true;
		}
	}
	else {
		Node* substitute = new Node;
		find_min(head, index->left, index, substitute);
		substitute->left = index->left->left;
		substitute->right = index->left->right;

		Node* kill = substitute;
		while (kill->left->value != substitute->value && kill->right->value != substitute->value)
		{
			if (substitute->value < kill->value)
				kill = kill->left;
			else
				kill = kill->right;
		}
		if (kill->right != nullptr && kill->right->value == substitute->value)
			kill->right = nullptr;
		if (kill->left != nullptr && kill->left->value == substitute->value)
			kill->left = nullptr;

		index->left = substitute;
		nr_node--;
		return true;
	}
}

bool Tree::delete_right(Node* index) {
	if (index->right->is_leaf() == true) {
		index->right = nullptr;
		nr_node--;
		return true;
	}
	else if (index->right->sons() == 1) {
		if (index->right->right != nullptr) {
			index->right = index->right->right;
			nr_node--;
			return true;
		}
		else {
			index->right = index->right->left;
			nr_node--;
			return true;
		}

	}
	else {
		Node* substitute = new Node;
		find_min(head, index, index->right, substitute);
		substitute->left = index->right->left;
		substitute->right = index->right->right;

		Node* kill = substitute;
		while (kill->left->value != substitute->value && kill->right->value != substitute->value)
		{
			if (substitute->value < kill->value)
				kill = kill->left;
			else
				kill = kill->right;
		}
		if (kill->right != nullptr && kill->right->value == substitute->value)
			kill->right = nullptr;
		if (kill->left != nullptr && kill->left->value == substitute->value)
			kill->left = nullptr;

		index->right = substitute;
		nr_node--;
		return true;
	}
}



bool Tree::remove(int val) {
	 Node* index = head;
	 if (is_empty() == true)
		 return false;
	 if (index->value == val) {
		 if (index->left != nullptr) {
			 head = head->left;
			 index = index->left;
			 nr_node--;
			 return true;
		 }
		 else {
			 head = head->right;
			 index = index->right;
			 nr_node--;
			 return true;
		 }
	 }


	 if (index->left != nullptr && index->left->value == val) {
		 return delete_left(index);
	 }
	 if (index->right != nullptr && index->right->value == val) {
		 return delete_right(index);
	 }
	 while (index->left!=nullptr && index->right!=nullptr && index->left->value != val  && index->right->value != val)
	 {
		 if (val < index->value)
			 index = index->left;
		 else
			 index = index->right;
	 }
	 if (index->left != nullptr && index->left->value == val) {
		 return delete_left(index);
	 }
	 if (index->right != nullptr && index->right->value == val) {
		 return delete_right(index);
	 }
	 return false;
}

void Tree::preorder(Node* start, std::string& s)
{
	//preorder
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
	delete head;
}