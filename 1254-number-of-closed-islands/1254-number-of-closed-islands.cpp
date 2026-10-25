class Solution {
public:
    int x[4] = {0 , 1 , 0 , -1};
    int y[4] = {1 , 0 , -1 , 0};
    void doit(int currx , int curry , int endx , int endy , vector<vector<int>>& grid){
        grid[currx][curry] = 2;
        for(int k = 0 ; k<4 ; k++){
            int newx = currx + x[k];
            int newy = curry + y[k];
            if(newx >=0 && newx < endx && newy >=0 && newy < endy && grid[newx][newy] == 0){
                doit(newx , newy , endx , endy , grid);
            }
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size() , n = grid[0].size();
        for(int i = 0  ; i<m ; i++){
            for(int j = 0 ; j<n ; j++){
                if((i == 0 || j == 0 || i == m-1 || j == n-1) && (grid[i][j] == 0)){
                    doit(i , j , m , n , grid);
                }
            }
        }



        int count = 0;
        for(int i = 0 ; i<m ; i++){
            for(int j = 0 ; j<n ; j++){
                if(grid[i][j] == 0){
                    doit(i , j , m , n , grid);
                    count++;
                }
            }
        }
        return count;
    }
};