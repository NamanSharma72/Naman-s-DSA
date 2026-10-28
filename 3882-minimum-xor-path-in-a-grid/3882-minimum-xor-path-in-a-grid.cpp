class Solution {
public:
    int doit(int currx , int curry , int endx , int endy , vector<vector<int>>& grid , int xo , vector<vector<vector<int>>> &dp){
        if(currx == endx-1 && curry == endy-1) return xo ^ grid[currx][curry];
        xo = xo ^ grid[currx][curry];
        if(dp[currx][curry][xo] != -1) return dp[currx][curry][xo];
        int right =  1e9 , down = 1e9;
        if(currx+1 < endx){
            down = doit(currx+1 , curry , endx , endy , grid , xo  , dp);
        } 
        if(curry+1 < endy){
            right = doit(currx , curry+1 , endx , endy , grid , xo , dp);
        }
        return dp[currx][curry][xo] = min(right , down);
    }
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size() , n = grid[0].size();
        vector<vector<vector<int>>> dp(m , vector<vector<int>>(n , vector<int>(1025 , -1)));
        return doit(0 , 0 , m , n , grid , 0 , dp);
    }
};