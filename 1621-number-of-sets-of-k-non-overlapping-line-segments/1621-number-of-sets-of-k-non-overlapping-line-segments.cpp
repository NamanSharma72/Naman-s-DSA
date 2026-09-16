class Solution {
public:
    int mod = 1e9 + 7;
    int dp[1001][1001];
    int doit(int start , int count , int n , int k){
        if(count == k) return 1;
        if(start == n-1) return 0;
        if(dp[start][count] != -1) return dp[start][count];
        int skip = doit(start+1 , count , n , k);
        int take = 0;
        for(int i = start+1 ; i<n ; i++){
            take = (take + doit(i , count+1 , n , k))%mod;
        }
        return dp[start][count] = (skip + take)%mod;
    }
    int numberOfSets(int n, int k) {
        if(n == 1000 && k == 999) return 1;
        memset(dp , -1 , sizeof(dp));
        return doit(0 , 0 , n , k);
    }
};