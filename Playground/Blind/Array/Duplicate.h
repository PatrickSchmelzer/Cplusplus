#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    // time O(n) / space O(n)
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seenNums;
        for (auto num : nums) {
            if (seenNums.find(num) != seenNums.end())
                return true;
            else
                seenNums.insert(num);
        }
        return false;
    }
};

//Input: [1, 2, 3, 1]
//Output : true