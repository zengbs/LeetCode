class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int maxProfit = 0;
        int buy = 0;

        for (int sell = 0; sell < prices.size(); sell++) {

            if ( prices[sell] < prices[buy] ) buy = sell;

            int profit = prices[sell] - prices[buy];

            if (profit > maxProfit) {
                maxProfit = profit;
            }
        }

        return maxProfit;
    }
};
