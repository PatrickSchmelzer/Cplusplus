//#include "AlgoExpert/Easy/BinarySearch.h"
//#include "AlgoExpert/Easy/PalindromCheck.h"
//#include "AlgoExpert/Easy/NthFibonacci.h"
//#include "AlgoExpert/Easy/FindClosestValueInBST.h"
//#include "AlgoExpert/Easy/TwoNumberSum.h"
//#include "AlgoExpert/Easy/FindThreeLargestNumbers.h"
#include "AlgoExpert/Easy/CeasarCypherEncryptor.h"

#include <iostream>
#include <algorithm>

int main()
{
	std::string str = "xyz";
	auto result = caesarCypherEncryptor(str, 2);
	std::cout << "Result: " << result << std::endl;
}
