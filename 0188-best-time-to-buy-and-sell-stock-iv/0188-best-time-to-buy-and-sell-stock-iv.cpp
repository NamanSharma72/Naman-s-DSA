class Solution {
public:
    int dp[1000][2][100];
    int doit(int idx , vector<int>& prices , int buy , int times , int k){
        if(idx == prices.size()) return 0;
        if(times == k) return 0;
        if(dp[idx][buy][times] != -1) return dp[idx][buy][times];
        int skip = doit(idx+1 , prices , buy , times , k);
        int buyKaro = 0;
        if(buy == 1) buyKaro = -prices[idx] + doit(idx+1 , prices , 0 , times , k);
        int sellKaro = 0;
        if(buy == 0) sellKaro = prices[idx] + doit(idx , prices , 1 , times+1 , k);
        return dp[idx][buy][times] = max(skip , max(buyKaro , sellKaro));
    }
    int maxProfit(int k , vector<int>& prices) {
        memset(dp , -1 , sizeof(dp));
        return doit(0 , prices , 1 , 0 , k);
    }
};