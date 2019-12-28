#include "Blind/Array/BuySellStock.h"

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	std::vector<int> arr{ 7,1,5,3,6,4 };
	Solution s;
	auto result = s.maxProfit2(arr);

	cout << "Result: " << result;
	//for (auto e : result)
	//	cout << e << " " << endl;
}
