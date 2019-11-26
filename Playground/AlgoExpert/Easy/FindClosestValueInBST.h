#ifndef ALGOEXPERT_FIND_CLOSEST_VALUE_IN_BST
#define ALGOEXPERT_FIND_CLOSEST_VALUE_IN_BST

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

static int findClosestValueInBst(BST* tree, int target) {
	double closest = DBL_MAX;
	binarySeach(tree, target, closest);
	return static_cast<int>(closest);
}

#endif // !ALGOEXPERT_FIND_CLOSEST_VALUE_IN_BST