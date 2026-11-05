class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> freq(201 , 0);
        for(int i = 0 ; i<nums.size() ; i++) freq[nums[i]+100]++;
        int index = 0;
        for(int i = 0 ; i<freq.size() ; i++){
            if(freq[i] > 0){
                nums[index] = i-100;
                index++;
            }
        }
        return index;
    }
};