class Solution {
public:
    int minDays(int n) {
        vector<int> dp(n+1 , INT_MAX);
        dp[0] = 0;
        for(int i = 1 ; i<= n ; i++){
            int take = INT_MAX;
            int days = 1;
            while(true){
                int points = (days * (days + 1))/2;
                if(points > i) break;
                if(i-points == 0) take = min(take , days);
                else take = min(take , 1 + days + dp[i-points]);
                days++;
            }
            dp[i] = take;
        }
        return dp[n];
    }
};