class Solution {
public:
    int dp[40][16384];
    int doit(int idx , vector<int>& nums , int target , int xo){
        if(idx == nums.size()){
            if(xo == target) return 0;
            return -50;
        }
        if(dp[idx][xo] != -1) return dp[idx][xo];
        int notTake = doit(idx+1 , nums , target , xo);
        int take = 1 + doit(idx+1 , nums , target , xo ^ nums[idx]);
        return dp[idx][xo] = max(take , notTake);
    }
    int minRemovals(vector<int>& nums, int target) {
        memset(dp , -1 , sizeof(dp));
        int use = doit(0 , nums , target , 0);
        if(use < 0) return -1;
        return nums.size()-use;
    }
};