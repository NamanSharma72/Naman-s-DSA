class Solution {
public:
    int dp[302][302];
    int doit(int i , int j , vector<int>& nums){
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int maxi = 0;
        for(int k = i ; k<=j ; k++){
            int use  = nums[k]*nums[i-1]*nums[j+1] + doit(i , k-1 , nums) + doit(k+1 , j , nums);
            maxi = max(maxi , use);
        }
        return dp[i][j] = maxi;
    }
    int maxCoins(vector<int>& nums) {
        vector<int> use = {1};
        for(int i = 0 ; i<nums.size() ; i++) use.push_back(nums[i]);
        use.push_back(1);
        memset(dp , -1 , sizeof(dp));
        return doit(1 , use.size()-2 , use);
    }
};