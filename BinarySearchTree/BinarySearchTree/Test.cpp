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
	assert(t.insert(8) == true);
	assert(t.insert(3) == true);
	assert(t.insert(10) == true);
	assert(t.insert(1) == true);
	assert(t.insert(6) == true);
	assert(t.insert(5) == true);
	assert(t.insert(7) == true);
	assert(t.insert(9) == true);
	assert(t.insert(13) == true);
	assert(t.insert(15) == true);
	assert(t.is_empty() == false);
	assert(t.countNodes() == 10);

}

void test_remove() {
	Tree t;
	assert(t.is_empty() == true);
	assert(t.insert(8) == true);
	assert(t.insert(3) == true);
	assert(t.insert(10) == true);
	assert(t.insert(1) == true);
	assert(t.insert(7) == true);
	assert(t.insert(5) == true);
	assert(t.insert(15) == true);
	assert(t.is_empty() == false);
	assert(t.countNodes() == 7);
	assert(t.remove(3) == true);
	assert(t.remove(3312) == false);
	assert(t.remove(1) == true);
	assert(t.remove(10) == true);
	assert(t.remove(15) == true);
	assert(t.remove(8) == true);
	assert(t.remove(7) == true);
	assert(t.remove(5) == true);
	assert(t.remove(-2) == false);
	assert(t.is_empty() == true);
	assert(t.countNodes() == 0);
}
void test_preorder() {
	Tree t;
	assert(t.is_empty() == true);
	assert(t.insert(8) == true);
	assert(t.insert(3) == true);
	assert(t.insert(10) == true);
	assert(t.insert(1) == true);
	assert(t.insert(7) == true);
	assert(t.insert(5) == true);
	assert(t.insert(15) == true);
	assert(t.is_empty() == false);
	assert(t.countNodes() == 7);
	std::string s = "";
	t.preorder(t.get_first(), s);
	assert(s.compare("8, 3, 1, 7, 5, 10, 15, ") == 0);
}



void runAllTests() {
	test_sons();
	test_get_value();
	test_add();
	test_remove();
	test_preorder();
}