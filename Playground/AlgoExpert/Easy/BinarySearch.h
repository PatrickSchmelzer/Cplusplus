#ifndef ALGOEXPERT_BINARY_SEARCH
#define ALGOEXPERT_BINARY_SEARCH

/// Binary Search
///
/// Write a function taht takes in a sorted array of integers as well as a target integer. The function should use the Binary Search algorithm
/// to find if the target number is contained in the array and s hould return its inded if tis is, otherwise -1;

//Usage:
//std::vector<int> array{ 0, 1, 21, 33, 45, 45, 61, 71, 72, 73 };
//BinarySearch b;
//auto result = b.binarySearch(array, 33);
//Result: 3

#include <vector>

class BinarySearch {
public:
	BinarySearch() = default;
	~BinarySearch() = default;

	/// Time complexity O(log(n)), Space complexity O(1)
	int binarySearch(std::vector<int> array, int target) {
		int left = 0;
		int right = array.size() - 1;

		while (left <= right) {
			int mid = left + ((right - left) / 2);
			if (array[mid] == target)
				return mid;
			else if (array[mid] > target)
				right = mid - 1;
			else
				left = mid + 1;
		}
		return -1; // not found
	}

	/// Time complexity O(log(n)), Space complexity O(log(n))
	int binarySearchRecurs(std::vector<int> array, int target) {
		return helper(array, target, 0, array.size() - 1);
	}

private:
	int helper(std::vector<int>& array, int target, int left, int right) {
		if (left > right)
			return -1;

		int mid = left + (right - left) / 2;
		if (array[mid] == target)
			return mid;
		else if (array[mid] > target)
			return helper(array, target, left, mid - 1);
		else
			return helper(array, target, mid + 1, right);
	}

};

#endif // !ALGOEXPERT_BINARY_SEARCH
