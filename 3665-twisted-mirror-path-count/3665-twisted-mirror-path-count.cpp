class Solution {
public:
    int mod = 1e9 + 7;
    int uniquePaths(vector<vector<int>>& grid){
        int m = grid.size() , n = grid[0].size();
        vector<vector<vector<int>>> dp(m , vector<vector<int>>(n , vector<int>(2 , 0)));
        dp[m-1][n-1][0] = 1;
        dp[m-1][n-1][1] = 1;
        for(int i = m-1 ; i>=0 ; i--){
            for(int j = n-1 ; j>=0 ; j--){
                if(i == m-1 && j == n-1) continue;
                for(int dir = 0 ; dir<=1 ; dir++){
                    int total = 0;
                    if(grid[i][j] == 0){
                        int right = 0 , down = 0;
                        if(i+1 < m) down = down + dp[i+1][j][0];
                        if(j+1 < n) right = right + dp[i][j+1][1];
                        total = (total + down)%mod;
                        total = (total+right)%mod;
                    }
                    else{
                        if(dir == 0){
                            if(j+1 < n)  total = (total + dp[i][j+1][1])%mod;
                        }
                        else{
                            if(i+1 < m) total = (total + dp[i+1][j][0])%mod;
                        }
                    }
                    dp[i][j][dir] = total;
                }
            }
        }
        return dp[0][0][1];
    }
};