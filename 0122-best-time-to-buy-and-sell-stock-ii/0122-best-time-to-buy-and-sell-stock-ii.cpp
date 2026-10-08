class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int nextBuyYes = 0 , nextBuyNo = 0;
        for(int idx = prices.size()-1 ; idx>=0 ; idx--){
            int currBuyYes = -prices[idx] + nextBuyNo;
            int currBuyNo = +prices[idx] + nextBuyYes;
            nextBuyYes = max(nextBuyYes , currBuyYes);
            nextBuyNo = max(nextBuyNo , currBuyNo);
        }
        return nextBuyYes;
    }
};