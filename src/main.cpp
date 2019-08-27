#include "binary_tree/BinaryTree.hpp"

int main()
{
	ds::BinaryTree binTree;

	// Build the tree
	/*			10
			   /   \
			  6	    14
			 / \	/ \
			5   8  11 18	
	*/
	binTree.insert(10);
	binTree.insert(6);
	binTree.insert(14);
	binTree.insert(5);
	binTree.insert(8);
	binTree.insert(11);
	binTree.insert(18);

	auto node = binTree.find(6);

	system("pause");
	return 0;
}