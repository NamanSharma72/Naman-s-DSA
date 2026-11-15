class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long sum = 0;
        for(int i = 0 ; i<nums.size() ; i++){
            sum+=nums[i];
        }
        if(sum%p == 0) return 0;
        int targetRem = sum%p;
        unordered_map<int , int> mpp;
        int mini = INT_MAX;
        long long currSum = 0;
        for(int i = 0 ; i<nums.size() ; i++){
            currSum+=nums[i];
            int currRem = currSum%p;
            int requiredRem = (currRem - targetRem + p)%p;
            if(currRem == targetRem && i < nums.size()-1) mini = min(mini , i+1);
            if(mpp.find(requiredRem) != mpp.end()){
                mini = min(mini , i-mpp[requiredRem]);
            }
            mpp[currRem] = i;
        }
        if(mini == INT_MAX) return -1;
        return mini;
    }
};