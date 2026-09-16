class Solution {
public:
    int mod = 1e9 + 7;
    int numberOfSets(int n, int k) {
        vector<vector<int>> dp(n , vector<int>(k+1 , 0));
        for(int start = 0 ; start<n ; start++) dp[start][k] = 1;
        for(int count = k-1 ; count>=0 ; count--){
            int suffix = 0;
            for(int start = n-2 ; start >=0 ; start--){
                suffix = (suffix + dp[start+1][count+1])%mod;
                int skip = dp[start+1][count];
                int take = suffix;
                dp[start][count] = (skip + take)%mod;
            }
        }
        return dp[0][0];
    }
};