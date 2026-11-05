class Solution {
public:
    // 0 means i have too buy and 1 means i will sell
    int dp[30000][2];
    int doit(int idx , vector<int>& prices , int hold){
        if(idx >= prices.size()) return 0;
        if(dp[idx][hold] != -1) return dp[idx][hold];
        int buy = 0;
        if(hold == 0){
            buy = -prices[idx] + doit(idx+1 , prices , 1);
        }
        int skip = doit(idx+1 , prices , hold);
        int sell = 0;
        if(hold == 1){
            sell = prices[idx] + doit(idx , prices , 0);
        }
        return dp[idx][hold] = max(buy , max(sell , skip));
    }
    int maxProfit(vector<int>& prices) {
        memset(dp , -1 , sizeof(dp));
        return doit(0 , prices , 0);
    }
};