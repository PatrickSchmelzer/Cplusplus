#ifndef ALGOEXPERT_FIND_CLOSEST_VALUE_IN_BST
#define ALGOEXPERT_FIND_CLOSEST_VALUE_IN_BST
 
/// Find Closest Value in BST
///
/// You are given a BST data structure consisting of BST nodes. Each BST node has an integer value stored in a property called "value" and 
/// two children nodes stored in properties called "left" and "right" respectively. A node is said to be a BST node if and only if it satisfies th BST propery:
/// its value is strictly greater than the values of evey nodes to ist left; its value is less than or equal to the values every node to ist right; and both 
/// of its children nodes are either BST nodes themselfe of None (nullptr) values. You are also given a target integer value; write a function that finds the closest
/// value to that target conained in the BST. Assume there will be only be on closest value.

// Example tree
// BST* tree = new BST(10)
// tree->left = new BST(5)
// tree->left->left = new BST(2)
// tree->left->left->left = new BST(1)
// tree->right = new BST(15)
// tree->right->left = new BST(13)
// tree->right->left->right = new BST(14)
// tree->right->right = new BST(22)
// Target = 12
// Result = 13


#include "float.h"
#include <cmath>

class BST {
public:
	int value;
	BST* left;
	BST* right;

	explicit BST(int val) : value(val), left(nullptr), right(nullptr) {}
	//BST& insert(int val);
};

static void binarySeach(BST* tree, int target, double& closest) {
	if (!tree)
		return;

	double currentDiff = std::abs(tree->value - target);
	double minDiff = std::abs(target - closest);

	if (currentDiff < minDiff)
		closest = tree->value;

	if (tree->value == target) {
		closest = target;
		return;
	}
	else if (tree->value > target) {
		binarySeach(tree->left, target, closest);
	}
	else {
		binarySeach(tree->right, target, closest);
	}

}

///Average: Time complexity O(log(n)), Space complexity O(log(n)) (because of recursive binary search)
///Worst: Time complexity O(n), Space complexity O(n)

///Average: Time complexity O(log(n)), Space complexity O(1) <-- that would be only true if the binary search would be implemented iteratively
///Worst: Time complexity O(n), Space complexity O(1) <-- that would be only true if the binary search would be implemented iteratively
static int findClosestValueInBst(BST* tree, int target) {
	double closest = DBL_MAX; // Note: double is needed because of abs(-1 - INT_MAX) overflows and double just looses precision
	binarySeach(tree, target, closest);
	return static_cast<int>(closest);
}

#endif // !ALGOEXPERT_FIND_CLOSEST_VALUE_IN_BST