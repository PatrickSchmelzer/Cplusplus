#ifndef ALGOEXPERT_TWO_NUMBER_SUM
#define ALGOEXPERT_TWO_NUMBER_SUM

/// Two number sum
///
/// Write a function that takes in a non-empty array of distinct integers and an integer representing a target sum. If any two numbers
/// in the input array sum up to the target sum, the function should return them in an array. If no two numbers sum up to the target sum, the
/// function should return an empty array. Assume that there will be at most on pair of numbers summing up to the target sum.

/// Example: std::vector<int> array{3,5,-4,8,11,1,-1,6}, target = 10
/// Result: {-1, 11}

#include <vector>
#include <unordered_set>

/// Time complexity O(n), Space complexity O(n) (sorting and two pointers would end up in nlog(n) for time and constant space
static std::vector<int> twoNumberSum(std::vector<int> array, int targetSum) {
	std::unordered_set<int> seenNumbers;
	std::vector<int> result;
	for (auto num : array) {
		int neededNumber = targetSum - num;
		if (seenNumbers.find(neededNumber) != seenNumbers.end()) {
			result.push_back(neededNumber);
			result.push_back(num);
		}
		else {
			seenNumbers.insert(num);
		}
	}
	return result;
}


#endif // !ALGOEXPERT_TWO_NUMBER_SUM

