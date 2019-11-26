#ifndef ALGOEXPERT_PALINDROM_CHECK
#define ALGOEXPERT_PALINDROM_CHECK

#include <string>

static bool isPalindrome(std::string str) {
	int left = 0;
	int right = str.size() - 1;

	while (left < right) {
		if (str[left] != str[right])
			return false;
		left++;
		right--;
	}
	return true;
}


#endif // !ALGOEXPERT_PALINDROM_CHECK

