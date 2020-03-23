#include "Test.h"
#include <cassert>
#include "Node.h"
#include "Tree.h"


void test_sons() {
	Node* a = new Node;
	Node* b = new Node;
	Node* c = new Node;

	a->value = 1;
	b->value = 3;
	c->value = 2;
	assert(a->is_leaf() == true);
	a->left = c;
	assert(a->sons() == 1);
	a->right = c;
	assert(a->sons() == 2);
	assert(a->is_leaf() == false);
}

void test_get_value() {
	Node* a = new Node;
	a->value = 1;
	assert(a->get_value() == 1);
	assert(a->get_value() != 31);
}

void test_add() {
	Tree t;
	assert(t.is_empty() == true);
	t.insert(8);
	t.insert(3);
	t.insert(10);
	t.insert(1);
	t.insert(6);
	t.insert(5);
	t.insert(7);
	t.insert(9);
	t.insert(13);
	t.insert(15);
	assert(t.is_empty() == false);
	assert(t.countNodes() == 10);

}



void runAllTests() {
	test_sons();
	test_get_value();
	test_add();
}