#ifndef ALGOEXPERT_PALINDROM_CHECK
#define ALGOEXPERT_PALINDROM_CHECK

/// Palindrom Check

/// Write a function that takes in a non-empty string and that returns a boolean representing whether or not the string is a palindrom.
/// A palindrom is defined as a string that is written the same forward and backward
///

/// Example: std::string str = "abcdcba"
/// Result: true

#include <string>

/// Time complexity O(n), Space complexity O(1)
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

