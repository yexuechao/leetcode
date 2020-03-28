class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }
        int min = prices[0];
        int result = 0;
        // vector<int> dp(prices.size(), 0);
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > min) {
                if (prices[i] - min > result) {
                    result = prices[i] - min;
                }
            }
            if (prices[i] < min) {
                min = prices[i];
            }
        }
        return result;
    }
};