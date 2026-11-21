class Solution {
public:
    int r[4] = {0,1,0,-1};
    int c[4] = {1,0,-1,0};
    int orangesRotting(vector<vector<int>>& grid) {
        int fresh = 0;
        queue<pair<int , int>> qt;
        int m = grid.size() , n = grid[0].size();
        for(int i = 0 ; i<m ; i++){
            for(int j = 0 ; j<n ; j++){
                if(grid[i][j] == 2) qt.push({i , j});
                else if(grid[i][j] == 1) fresh++;
            }
        }
        int minutes = 0;
        while(fresh > 0 && !qt.empty()){
            int s = qt.size();
            for(int i = 0 ; i<s ; i++){
                int currx = qt.front().first;
                int curry = qt.front().second;
                qt.pop();
                for(int k = 0 ; k<4 ; k++){
                    int newx = currx + r[k] , newy = curry + c[k];
                    if(newx >=0 && newx < m && newy >=0 && newy < n && grid[newx][newy] == 1){
                        fresh--;
                        grid[newx][newy] = 3;
                        qt.push({newx , newy});
                    }
                }
            }
            minutes++;
        }
        if(fresh > 0) return -1;
        return minutes;
    }
};