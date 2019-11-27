#ifndef ALGOEXPERT_FIND_THREE_LARGEST_NUMBRES
#define ALGOEXPERT_FIND_THREE_LARGEST_NUMBRES

/// Find the three Largest Numbers
///
/// Write a function that takes in an array of integers and returns a sorted array of the three largest integers in the input array.
/// Note that the function should return duplicate integers if necessary; for example it should return 10,10,12 for an input array of 
/// [10, 5, 9, 10]
///

/// Sample input: std::vector<int> array{141,1,17,-7,-17,-27,18,541,8,7,7}
// Result: {18,141,541}

#include <vector>
#include <limits>

/// Time complexity O(n), Space complexity O(1)
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

