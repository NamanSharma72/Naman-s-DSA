class Solution {
public:
    int dp[101][101];
    int doit(int i , int j , vector<int>& cuts){
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int mini = INT_MAX;
        for(int k = i ; k<=j ; k++){
            mini = min(mini , cuts[j+1]-cuts[i-1] + doit(i , k-1 , cuts) + doit(k+1 , j , cuts));
        }
        return dp[i][j] = mini;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin() , cuts.end());
        memset(dp , -1 , sizeof(dp));
        return doit(1 , cuts.size()-2 , cuts);
    }
};