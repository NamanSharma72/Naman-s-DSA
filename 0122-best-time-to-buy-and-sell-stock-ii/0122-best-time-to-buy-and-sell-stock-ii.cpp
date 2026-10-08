class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size()+1 , vector<int>(2 , 0));
        dp[prices.size()][0] = 0;
        dp[prices.size()][1] = 0;
        for(int idx = prices.size()-1 ; idx>=0 ; idx--){
            for(int buy = 0 ; buy <= 1 ; buy++){
                int skip = dp[idx+1][buy];
                int buyKaro = 0;
                if(buy == 1) buyKaro = -prices[idx] + dp[idx+1][0];
                int sellKaro = 0;
                if(buy == 0) sellKaro = prices[idx] + dp[idx+1][1];
                dp[idx][buy] = max(skip , max(buyKaro , sellKaro));
            }
        }
        return dp[0][1];
    }
};