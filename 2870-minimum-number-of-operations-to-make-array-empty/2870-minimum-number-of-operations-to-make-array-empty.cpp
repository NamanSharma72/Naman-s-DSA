class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int , int> freq;
        for(int i = 0 ; i<nums.size() ; i++) freq[nums[i]]++;
        int ans = 0;
        for(auto &it : freq){
            if(it.second == 1) return -1;
            int count = it.second/3;
            if(it.second%3 != 0) count++;
            ans+=count;
        }
        return ans;
    }
};