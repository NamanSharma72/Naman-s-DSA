class Solution {
public:
    int x[4] = {0 , 1 , 0 , -1};
    int y[4] = {1 , 0 , -1 , 0};
    int doit(int currx , int curry , int endx , int endy , vector<vector<int>> &visited , vector<vector<int>>& grid){
        int maxi = 0;
        visited[currx][curry] = 1;
        for(int k = 0 ; k<4 ; k++){
            int newx = currx + x[k];
            int newy = curry + y[k];
            if(newx >=0 && newx < endx && newy >=0 && newy < endy && visited[newx][newy] == 0 && grid[newx][newy] != 0){
                int karo = doit(newx , newy , endx , endy , visited , grid);
                maxi = max(maxi , karo);
            }
        }
        visited[currx][curry] = 0;
        return maxi + grid[currx][curry];
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int maxi = 0;
        int m = grid.size() , n = grid[0].size();
        for(int i = 0 ; i<m ; i++){
            for(int j = 0 ; j<n ; j++){
                if(grid[i][j] != 0){
                    vector<vector<int>> visited(m , vector<int>(n));
                    int value = doit(i , j , m , n , visited , grid);
                    maxi = max(maxi , value);
                }
            }
        }
        return maxi;
    }
};