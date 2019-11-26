#ifndef ALGOEXPERT_FIND_THREE_LARGEST_NUMBRES
#define ALGOEXPERT_FIND_THREE_LARGEST_NUMBRES

#include <vector>
#include <limits>

std::vector<int> findThreeLargestNumbers(std::vector<int> array) {
	std::vector<int> maxValues(3, INT_MIN);

	for (auto num : array) {
		if (num > maxValues[2]) {
			maxValues[0] = maxValues[1];
			maxValues[1] = maxValues[2];
			maxValues[2] = num;
		}
		else if (num > maxValues[1]) {
			maxValues[0] = maxValues[1];
			maxValues[1] = num;
		}
		else if(num > maxValues[0]){
			maxValues[0] = num;
		}
		else {
			// mandatory else statement
		}

	}
	return maxValues;
}


#endif // !ALGOEXPERT_FIND_THREE_LARGEST_NUMBRES

