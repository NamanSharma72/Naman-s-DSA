class Solution {
public:
    int dp[30][6001];
    int doit(int idx , vector<int>& stones , int diff){
        if(idx == stones.size()){
            return abs(diff);
        }
        if(dp[idx][diff+3000] != -1) return dp[idx][diff+3000];
        int first = doit(idx+1 , stones , diff + stones[idx]);
        int second = doit(idx+1 , stones , diff - stones[idx]);
        return dp[idx][diff+3000] = min(first , second);
    }
    int lastStoneWeightII(vector<int>& stones) {
        memset(dp , -1 , sizeof(dp));
        return doit(0 , stones , 0);
    }
};