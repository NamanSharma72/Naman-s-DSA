class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int maxInc = 1 , maxDec = 1 , countInc = 1 , countDec = 1;
        for(int i = 1 ; i<nums.size() ; i++){
            countInc = nums[i] > nums[i-1] ? countInc+1 : 1;
            countDec = nums[i] < nums[i-1] ? countDec+1 : 1;
            maxInc = max(maxInc , countInc);
            maxDec = max(maxDec , countDec);
        }
        return max(maxInc , maxDec);
    }
};