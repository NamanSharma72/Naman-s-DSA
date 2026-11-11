class Solution {
public:
    int countSuffix(vector<int>& nums, vector<int>& target) {
        int threshold = target.size()-1;
        for(int i = target.size()-2 ; i>=0 ; i--){
            if(target[i] >= target[i+1]) threshold = i;
            else break;
        }
        vector<bool> equality(nums.size() , false);
        vector<int> diff(100001, 0);
        int different = 0;
        for(int i = target.size()-1; i >= 0; i--) {
            if(diff[nums[i]] == 0) different++;
            diff[nums[i]]++;
            if(diff[nums[i]] == 0) different--;

            if(diff[target[i]] == 0) different++;
            diff[target[i]]--;
            if(diff[target[i]] == 0) different--;

            if(different == 0)
                equality[i] = true;
        }
        int ans = 0;
        for(int i = 0 ; i<nums.size() ; i++){
            if(nums[i] != target[i]){
                if(i >= threshold && equality[i]) ans++;
                break;
            }
            else{
                if(i >= threshold && equality[i]) ans++;
            }
        }
        return ans;
    }
};