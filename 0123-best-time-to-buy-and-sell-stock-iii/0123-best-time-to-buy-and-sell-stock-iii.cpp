class Solution {
public:
    int dp[100000][2][2];
    int doit(int idx , vector<int>& prices , int buy , int times){
        if(idx == prices.size()) return 0;
        if(times == 2) return 0;
        if(dp[idx][buy][times] != -1) return dp[idx][buy][times];
        int skip = doit(idx+1 , prices , buy , times);
        int buyKaro = 0;
        if(buy == 1) buyKaro = -prices[idx] + doit(idx+1 , prices , 0 , times);
        int sellKaro = 0;
        if(buy == 0) sellKaro = prices[idx] + doit(idx , prices , 1 , times+1);
        return dp[idx][buy][times] = max(skip , max(buyKaro , sellKaro));
    }
    int maxProfit(vector<int>& prices) {
        memset(dp , -1 , sizeof(dp));
        return doit(0 , prices , 1 , 0);
    }
};