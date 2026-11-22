class Solution {
public:
    int dp[5000][2];
    int doit(int idx , vector<int>& prices , int hold){
        if(idx >= prices.size()) return 0;
        if(dp[idx][hold] != -1) return dp[idx][hold];
        int buy = 0 , sell = 0;
        int skip = doit(idx+1 , prices , hold);
        if(hold == 0){
            buy = -prices[idx] + doit(idx+1 , prices , 1);
        }
        if(hold == 1) sell = prices[idx] + doit(idx+2 , prices , 0);
        return dp[idx][hold] = max(buy , max(sell , skip));
    }
    int maxProfit(vector<int>& prices) {
        // o means not holding ans 1 means holding
        memset(dp , -1 , sizeof(dp));
        return doit(0 , prices , 0);
    }
};