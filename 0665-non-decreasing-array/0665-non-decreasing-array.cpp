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
        int maxBeforeIndex = INT_MIN;
        for(int i = 0 ; i<index ; i++) maxBeforeIndex = max(maxBeforeIndex , nums[i]);
        int flag = 0;
        for(int i = index+1 ; i<nums.size()-1 ; i++){
            if(nums[i] > nums[i+1] || nums[i] < maxBeforeIndex) flag = 1;
        }
        if(nums[nums.size()-1] < maxBeforeIndex) flag = 1;
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