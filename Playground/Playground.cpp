#include "Blind/Array/TwoSum.h"

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	std::vector<int> arr{ 2, 7, 11, 15 };
	Solution s;
	auto result = s.twoSum2(arr, 9);

	cout << "Result: ";
	for (auto e : result)
		cout << e << " " << endl;
}
