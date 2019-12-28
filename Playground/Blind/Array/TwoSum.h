#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_set>

using namespace std;

// giving back the two numbes which add up to a specified target sum, (if the indices are need, a map instead of a set needs to be used
// in the 2nd implementation

class Solution {
public:
    // time O(nlogn) space O(1)
    vector<int> twoSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            int number = nums[left] + nums[right];
            if (number == target)
                return { nums[left], nums[right] };
            else if (number > target)
                right--;
            else 
                left++;
        }

        return { -1, -1 };
    }   

    // time O(n) space O(n)
    vector<int> twoSum2(vector<int>& nums, int target) {
        unordered_set<int> seenNums;

        for (auto num : nums) {
            int neededNumber = target - num;
            if (seenNums.find(neededNumber) != seenNums.end()) {
                return { neededNumber, num };
            }
            else
                seenNums.insert(num);
        }
        return { -1, -1 };

    }
};