#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // kadanes algorithm
    int maxProfit(vector<int>& prices) {
        int maxCur = 0;
        int maxSoFar = 0;

        for (int i = 1; i < prices.size(); ++i) {
            maxCur = std::max(0, maxCur + prices[i] - prices[i - 1]);
            maxSoFar = std::max(maxCur, maxSoFar);
        }
        return maxSoFar;
    }


    int maxProfit2(vector<int>& prices) {
        int maxPro = 0;
        int minPrice = INT_MAX;
        for (int i = 0; i < prices.size(); i++) {
            minPrice = min(minPrice, prices[i]);
            maxPro = max(maxPro, prices[i] - minPrice);
        }
        return maxPro;
    }
};


//Input: [7, 1, 5, 3, 6, 4]
//Output : 5
//Explanation : Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6 - 1 = 5.
//Not 7 - 1 = 6, as selling price needs to be larger than buying price.

// minPrice = 1
// maxPro = 5
