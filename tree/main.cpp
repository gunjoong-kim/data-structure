#include "BST.hpp"
#include "AVL.hpp"
#include <stdlib.h>

int main()
{
	AVL test;

	test.insert_node(1);
	test.insert_node(3);
	test.insert_node(-1);
	test.insert_node(10);
	test.insert_node(11);
	test.insert_node(2);

	test.print_tree();

	test.delete_node(1);

	test.print_tree();

	test.delete_node(11);

	test.print_tree();

	AVL copy = test;
	copy.print_tree();

	AVL another_copy;

	another_copy.insert_node(11);
	another_copy.insert_node(12);

	another_copy.print_tree();
	another_copy = copy;
	another_copy.print_tree();
}