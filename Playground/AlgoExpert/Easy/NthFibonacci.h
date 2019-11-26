#ifndef ALGOEXPERT_NTH_FIBONACCI
#define ALGOEXPERT_NTH_FIBONACCI

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
