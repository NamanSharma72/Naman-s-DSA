class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0];
        int ans = 0;
        for(int i = 0 ; i<prices.size() ; i++){
            if(prices[i] > mini) ans+=(prices[i] - mini);
            mini = prices[i];
        }
        return ans;
    }
};