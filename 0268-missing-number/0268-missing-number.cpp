class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int original = (n * (n+1))/2;
        int given = 0;
        for(int i = 0 ; i<nums.size() ; i++) given+=nums[i];
        return original - given;
    }
};