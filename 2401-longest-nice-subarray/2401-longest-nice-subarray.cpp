class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int l = 0, r = 1;
        int an = nums[0];
        int maxi = 1;
        while(r < nums.size()){
            while(((an & nums[r]) != 0) && (l < r)){
                an = an ^ nums[l];
                l++;
            }
            an = an | nums[r];
            maxi = max(maxi , r-l+1);
            r++;
        }
        return maxi;
    }
};