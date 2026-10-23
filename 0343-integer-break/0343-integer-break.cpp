class Solution {
public:
    int dp[59];
    int doit(int n , int start){
        if(n == 0) return 1;
        if(dp[n] != -1) return dp[n];
        int maxi = 1;
        for(int i = 1 ; i<=n ; i++){
            if(n == start && i == n) continue;
            int use = i * doit(n-i , start);
            maxi = max(maxi , use);
        }
        return dp[n] = maxi;
    }
    int integerBreak(int n) {
        memset(dp , -1 , sizeof(dp));
        return doit(n , n);
    }
};