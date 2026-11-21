class Solution {
public:
    int r[4] = {0,1,0,-1};
    int c[4] = {1,0,-1,0};
    void solve(vector<vector<char>>& board) {
        int m = board.size() , n = board[0].size();
        queue<pair<int,int>> qt;
        for(int i = 0 ; i<m ; i++){
            for(int j = 0 ; j<n ; j++){
                if((i == 0 || j == 0 || i == m-1 || j == n-1) && board[i][j] == 'O'){
                    board[i][j] = 'S';
                    qt.push({i,j});
                }
            }
        }
        while(!qt.empty()){
            int currx = qt.front().first;
            int curry = qt.front().second;
            qt.pop();
            for(int i = 0 ; i<4 ; i++){
                int newx = currx + r[i] , newy = curry + c[i];
                if(newx >=0 && newx < m && newy >=0 && newy < n && board[newx][newy] == 'O'){
                    board[newx][newy] = 'S';
                    qt.push({newx , newy});
                }
            }
        }
        for(int i = 0 ; i<m ; i++){
            for(int j = 0 ; j<n ; j++){
                if(board[i][j] == 'O') board[i][j] = 'X';
                else if(board[i][j] == 'S') board[i][j] = 'O';
            }
        }
    }
};