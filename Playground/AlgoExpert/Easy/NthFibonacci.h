#ifndef ALGOEXPERT_NTH_FIBONACCI
#define ALGOEXPERT_NTH_FIBONACCI

///
/// Nth Fibonacci
///
/// The fibonacci sequence is defined as follows: the first number of the sequence is 0, the second number is 1 and the nth number is the sum of
/// n-1th and n-2th numbers. Write a function that takes an integer n and returns the nth fibonacci number

// Sample input: 6
// Result: 5 (0,1,1,2,3,5)

/// Time complexity O(n), Space complexity O(1)
static int getNthFib(int n) {
	if (n == 0)
		return -1;
	if (n == 1)
		return 0;
	if (n == 2)
		return 1;

	int lastlast = 0;
	int last = 1;

	for (int i = 3; i <= n; ++i) {
		int current = last + lastlast;
		lastlast = last;
		last = current;
	}
	return last;
}


#endif // !ALGOEXPERT_NTH_FIBONACCI
