class Solution {
public:
    int countStaircase(vector<int>& nums) {
        int count = 0;
        for(int i = 0 ; i<nums.size() ; i++){
            int distinct = 0;
            unordered_map<int , int> mpp;
            unordered_map<int , int> freq;
            int valid = 0;
            for(int j = i ; j<nums.size() ; j++){
                if(freq[nums[j]] == 0   ) {
                    distinct++;
                    mpp[nums[j]] = distinct;
                }
                freq[nums[j]]++;
                if(freq[nums[j]] > mpp[nums[j]]) valid--;
                if(freq[nums[j]] == mpp[nums[j]]) valid++;
                if(valid == distinct) count++;
            }
        }
        return count;
    }
};