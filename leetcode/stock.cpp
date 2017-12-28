class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = 0, buy_candidate = 0, max = 0;

        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i] - prices[buy_candidate] > max)
            {
                max = prices[i] - prices[buy_candidate];
                buy = buy_candidate;
            }

            if (prices[i] < prices[buy_candidate])
                buy_candidate = i;
        }

        return max;
    }
};

