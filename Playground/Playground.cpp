//#include "AlgoExpert/Easy/BinarySearch.h"
//#include "AlgoExpert/Easy/PalindromCheck.h"
//#include "AlgoExpert/Easy/NthFibonacci.h"
//#include "AlgoExpert/Easy/FindClosestValueInBST.h"
//#include "AlgoExpert/Easy/TwoNumberSum.h"
#include "AlgoExpert/Easy/FindThreeLargestNumbers.h"

#include <iostream>
#include <algorithm>

int main()
{
	std::vector<int> array{ 141, 1, 17, -7, -17, -27, 18, 541, 8, 7, 7 };
	auto result = findThreeLargestNumbers(array);
	std::for_each(result.begin(), result.end(), [](int n) {std::cout << n << " "; });
	//std::cout << "Result: " << result << std::endl;
}
