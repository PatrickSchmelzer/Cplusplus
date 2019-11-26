#ifndef ALGOEXPERT_TWO_NUMBER_SUM
#define ALGOEXPERT_TWO_NUMBER_SUM

#include <vector>
#include <unordered_set>

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

