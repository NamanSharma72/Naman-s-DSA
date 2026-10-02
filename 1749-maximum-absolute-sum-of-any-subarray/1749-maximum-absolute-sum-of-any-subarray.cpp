class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxi = 0 , posSum = 0 , mini = 0 , negSum = 0;
        for(int i = 0 ; i<nums.size() ; i++){
            posSum = posSum < 0 ? nums[i] : posSum+=nums[i];
            negSum = negSum > 0 ? nums[i] : negSum+=nums[i];
            maxi = max(maxi , posSum);
            mini = min(mini , negSum);
        }
        return max(maxi , abs(mini));
    }
};