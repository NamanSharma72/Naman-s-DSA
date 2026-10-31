class Solution {
public:
    int mod = 1e9 + 7;
    int dp[500][500][3];
    int doit(int currx , int curry , int endx , int endy , vector<vector<int>>& grid , int dir){
        if(currx == endx-1 && curry == endy-1) return 1;
        if(currx < 0 || currx >= endx || curry < 0 || curry >= endy) return 0;
        if(dp[currx][curry][dir] != -1) return dp[currx][curry][dir];
        int total = 0;
        if(grid[currx][curry] == 0){
            int down = 0 , right = 0;
            down+=doit(currx+1 , curry , endx , endy , grid , 1);
            right+=doit(currx, curry+1 , endx , endy , grid , 2);
            total = (total+down)%mod;
            total = (total+right)%mod;
        }
        else{
            if(dir == 1){
                if(curry+1 < endy) total = (total + doit(currx , curry+1 , endx , endy , grid , 2))%mod;
            }
            else{
                if(currx+1 < endx) total = (total+doit(currx+1 , curry , endx , endy , grid , 1))%mod;
            }
        }
        return dp[currx][curry][dir] = total;
    }
    int uniquePaths(vector<vector<int>>& grid){
        int m = grid.size() , n = grid[0].size();
        memset(dp , -1 , sizeof(dp));
        return doit(0 , 0 , m , n , grid , 0);
    }
};