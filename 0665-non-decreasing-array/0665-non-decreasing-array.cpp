class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int index = -1;
        for(int i = 0 ; i<nums.size()-1 ; i++){
            if(nums[i] > nums[i+1]){
                if(index == -1) index = i;
                else return false;
            }
        }
        int maxBeforeIndex = index-1 < 0 ? INT_MIN : nums[index-1];
        int flag = 0;
        for(int i = index+1 ; i<nums.size(); i++){
            if(nums[i] < maxBeforeIndex) flag = 1;
        }
        if(flag == 0) return true;
        int maxTillIndex = max(maxBeforeIndex , nums[index]);
        int countLess = 0;
        for(int i = index+1 ; i<nums.size() ; i++){
            if(nums[i] < maxTillIndex) countLess++;
        }
        if(countLess <= 1) return true;
        return false;
    }
};