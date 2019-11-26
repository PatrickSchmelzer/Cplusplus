#include "AlgoExpert/Easy/BinarySearch.h"

#include <vector>
#include <iostream>

int main()
{
	std::vector<int> array{ 0, 1, 21, 33, 45, 45, 61, 71, 72, 73 };
	BinarySearch b;
	auto result = b.binarySearchRecurs(array, 33);
	std::cout << "Result: " << result << std::endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
