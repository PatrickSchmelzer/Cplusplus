//#include "AlgoExpert/Easy/BinarySearch.h"
//#include "AlgoExpert/Easy/PalindromCheck.h"
//#include "AlgoExpert/Easy/NthFibonacci.h"
//#include "AlgoExpert/Easy/FindClosestValueInBST.h"
#include "AlgoExpert/Easy/TwoNumberSum.h"

#include <iostream>
#include <algorithm>

int main()
{
	std::vector<int> array{ 3,5,-4,8,11,1,-1,6 };
	auto result = twoNumberSum(array, 10);
	std::for_each(result.begin(), result.end(), [](int n) {std::cout << n << " "; });
	//std::cout << "Result: " << result << std::endl;
}
