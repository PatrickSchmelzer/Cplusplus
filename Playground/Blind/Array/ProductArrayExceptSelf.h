#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> fromBegin(n);
        fromBegin[0] = 1;
        vector<int> fromLast(n);
        fromLast[0] = 1;

        for (int i = 1; i < n; i++) {
            fromBegin[i] = fromBegin[i - 1] * nums[i - 1];
            fromLast[i] = fromLast[i - 1] * nums[n - i];
        }

        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            res[i] = fromBegin[i] * fromLast[n - 1 - i];
        }
        return res;
    }
};

//Input: [1, 2, 3, 4]
//Output : [24, 12, 8, 6]


// 1 1 2 6
// 1 4 12 24