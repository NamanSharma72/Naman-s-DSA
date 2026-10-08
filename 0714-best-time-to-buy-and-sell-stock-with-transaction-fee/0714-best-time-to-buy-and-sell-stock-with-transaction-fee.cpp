class Solution {
public:
    int dp[50000][2];
    int doit(int idx , vector<int>& prices , int buy , int fee){
        if(idx == prices.size()) return 0;
        if(dp[idx][buy] != -1) return dp[idx][buy];
        int skip = doit(idx+1 , prices , buy , fee);
        int buyKaro = 0;
        if(buy == 1) buyKaro = -prices[idx] + doit(idx+1 , prices , 0 , fee);
        int sellKaro = 0;
        if(buy == 0) sellKaro = prices[idx] - fee + doit(idx+1 , prices , 1 , fee);
        return dp[idx][buy] = max(skip , max(buyKaro , sellKaro));
    }
    int maxProfit(vector<int>& prices , int fee) {
        memset(dp , -1 , sizeof(dp));
        return doit(0 , prices , 1 , fee);
    }
};