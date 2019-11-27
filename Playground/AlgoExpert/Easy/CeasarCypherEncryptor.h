#ifndef ALGOEXPERT_CEASAR_CYPHER_ENCRYPTOR
#define ALGOEXPERT_CEASAR_CYPHER_ENCRYPTOR

/// Caesar Cypher Encryptor
///
/// Given a non-empty string of lowercase letters and a non-negative integer value representing a key, write a function that returns a new string
/// obtained by shifting every letter in the input string by k positions in the alphabet, where k is the key. Note that letters should wrap
/// around the alphabet; in other words, the letter "z" shifted by 1 returns the letter "a"

/// Sample input: "xyz", key: 2
/// Result: "zab"

#include <string>

// z (122) % 122 = 0

/// Time complexity O(n), Space complexity O(1) <- Algoexpert does not thing about using the input string
std::string caesarCypherEncryptor(std::string str, int key) {
	key %= 26; //if the key overflows

	for (int i = 0; i < str.size(); ++i) {
		auto tmp = str[i] + key;
		str[i] = (tmp < 123) ? tmp : ((str[i] + key) % 122) + 96;
	}
	return str;
}

// if a new string has to be created
/// Time complexity O(n), Space complexity O(n)
std::string caesarCypherEncryptor(std::string str, int key) {
	key %= 26; //if the key overflows
	std::string newString(str.size(), ' ');

	for (int i = 0; i < str.size(); ++i) {
		auto tmp = str[i] + key;
		newString[i] = (tmp < 123) ? tmp : ((str[i] + key) % 122) + 96;
	}
	return newString;
}


#endif // !ALGOEXPERT_CEASAR_CYPHER_ENCRYPTOR
