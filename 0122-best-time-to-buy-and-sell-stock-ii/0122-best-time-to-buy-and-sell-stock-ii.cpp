class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // vector<vector<int>> dp(prices.size()+1 , vector<int>(2 , 0));
        vector<int> next(2 , 0);
        vector<int> curr(2 , 0);
        for(int idx = prices.size()-1 ; idx>=0 ; idx--){
            for(int buy = 0 ; buy <= 1 ; buy++){
                int skip = next[buy];
                int buyKaro = 0 , sellKaro = 0;
                if(buy == 1) buyKaro = -prices[idx] + next[0];
                if(buy == 0) sellKaro = prices[idx] + next[1];
                curr[buy] = max(skip , max(buyKaro , sellKaro));
            }
            swap(next , curr);
        }
        return next[1];
    }
};