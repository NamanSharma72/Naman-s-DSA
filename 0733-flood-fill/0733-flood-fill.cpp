class Solution {
public:
    int r[4] = {0,1,0,-1};
    int c[4] = {1 , 0 , -1 , 0};
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oColor = image[sr][sc];
        int m = image.size() , n = image[0].size();
        if(oColor == color) return image;
        queue<pair<int , int>> qt;
        qt.push({sr ,sc});
        image[sr][sc] = color;
        while(!qt.empty()){
            int currx = qt.front().first;
            int curry = qt.front().second;
            qt.pop();
            for(int i = 0 ;i<4 ; i++){
                int newx = currx + r[i] , newy = curry + c[i];
                if(newx >=0 && newx < m && newy >=0 && newy < n && image[newx][newy] == oColor){
                    image[newx][newy] = color;
                    qt.push({newx ,newy});
                }
            }
        }
        return image;
    }
};