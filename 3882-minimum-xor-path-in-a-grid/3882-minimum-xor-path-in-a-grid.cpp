class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size() , n = grid[0].size();
        vector<vector<int>> curr(n , vector<int>(1024 , 0));
        for(int xo = 0 ; xo<1024 ; xo++) curr[n-1][xo] = xo;
        for(int i = m-1 ; i>=0 ; i--){
            for(int j = n-1 ; j>=0 ; j--){
                if(i == m-1 && j == n-1) continue;
                for(int xo = 0 ; xo < 1024 ; xo++){
                    int right = 1e9 , down = 1e9;
                    if(i+1 < m) down = curr[j][xo^grid[i+1][j]];
                    if(j+1 < n) right = curr[j+1][xo^grid[i][j+1]];
                    curr[j][xo] = min(down , right);
                }
            }
        }
        return curr[0][grid[0][0]];
    }
};