class Solution {
public:
    int mod = 1e9 + 7;
    int uniquePaths(vector<vector<int>>& grid){
        int m = grid.size() , n = grid[0].size();
        vector<vector<int>> next(n , vector<int>(2 , 0));
        vector<vector<int>> curr(n , vector<int>(2 , 0));
        curr[n-1][0] = 1;
        curr[n-1][1] = 1;
        for(int i = m-1 ; i>=0 ; i--){
            for(int j = n-1 ; j>=0 ; j--){
                if(i == m-1 && j == n-1) continue;
                for(int dir = 0 ; dir<=1 ; dir++){
                    int total = 0;
                    if(grid[i][j] == 0){
                        int right = 0 , down = 0;
                        if(i+1 < m) down = down + next[j][0];
                        if(j+1 < n) right = right + curr[j+1][1];
                        total = (total + down)%mod;
                        total = (total+right)%mod;
                    }
                    else{
                        if(dir == 0){
                            if(j+1 < n)  total = (total + curr[j+1][1])%mod;
                        }
                        else{
                            if(i+1 < m) total = (total + next[j][0])%mod;
                        }
                    }
                    curr[j][dir] = total;
                }
            }
            swap(curr , next);
        }
        return next[0][0];
    }
};