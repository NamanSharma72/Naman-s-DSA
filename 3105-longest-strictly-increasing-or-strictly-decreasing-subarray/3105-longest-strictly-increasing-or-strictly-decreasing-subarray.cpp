class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int maxInc = 1 , maxDec = 1;
        int countInc = 1 , countDec = 1;
        for(int i = 1 ; i<nums.size() ; i++){
            if(nums[i] > nums[i-1]) countInc++;
            else countInc = 1;
            if(nums[i] < nums[i-1]) countDec++;
            else countDec = 1;
            maxInc = max(maxInc , countInc);
            maxDec = max(maxDec , countDec);
        }
        return max(maxInc , maxDec);
    }
};