class Solution {
public:
    int findGCD(vector<int>& nums) {
        int large = *max_element(nums.begin() , nums.end());
        int small = *min_element(nums.begin() , nums.end());
        while(small != 0){
            int store = small;
            small = large%small;
            large = store;
        }
        return large;
    }
};