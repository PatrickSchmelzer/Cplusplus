//#include "AlgoExpert/Easy/BinarySearch.h"
//#include "AlgoExpert/Easy/PalindromCheck.h"
//#include "AlgoExpert/Easy/NthFibonacci.h"
#include "AlgoExpert/Easy/FindClosestValueInBST.h"

#include <iostream>

int main()
{
	BST* tree = new BST(10);
	tree->left = new BST(5);
	tree->left->left = new BST(2);
	tree->left->right = new BST(5);
	tree->left->left->left = new BST(1);
	tree->right = new BST(15);
	tree->right->left = new BST(13);
	tree->right->left->right = new BST(14);
	tree->right->right = new BST(22);

	auto result = findClosestValueInBst(tree, 12);
	std::cout << "Result: " << result << std::endl;
}
