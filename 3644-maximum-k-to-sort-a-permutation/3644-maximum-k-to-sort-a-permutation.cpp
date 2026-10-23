class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int bit = -1;
        for(int i = 0 ; i<nums.size() ; i++){
            if(i != nums[i]){
                if(bit == -1) bit = nums[i];
                else bit = bit & nums[i];
            }
        }
        if(bit == -1) return 0;
        return bit;
    }
};