class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        // max and third min
        int first = nums[nums.size()-1] - nums[2];
        // min and third max
        int second = nums[nums.size()-3] - nums[0];
        // second min and second max
        int third = nums[nums.size()-2] - nums[1];
        return min(first , min(second , third));
    }
};