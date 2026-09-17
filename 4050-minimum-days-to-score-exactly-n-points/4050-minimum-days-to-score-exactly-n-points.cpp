class Solution {
public:
    int dp[100001];
    int doit(int n){
        if(n == 0) return 0;
        if(dp[n] != -1) return dp[n];
        int take = INT_MAX;
        int days = 1;
        while(true){
            int points = (days *(days+1))/2;
            if(points > n) break;
            int ans;
            if(n-points == 0) ans = days;
            else ans = 1 + days + doit(n - points);
            take = min(take , ans);
            days++;
        }
        return dp[n] = take;
    }
    int minDays(int n) {
        memset(dp , -1 , sizeof(dp));
        return doit(n);
    }
};