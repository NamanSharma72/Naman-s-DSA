class Solution {
public:
    int count = 0;
    void doit(int idx , vector<int>& nums , int maxi , int xo){
        if(idx == nums.size()){
            if(xo == maxi) count++;
            return;
        }
        doit(idx+1 , nums , maxi , xo | nums[idx]);
        doit(idx+1 ,  nums , maxi , xo);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        // vector<int> freq(32 , 0);
        // for(int i = 0 ; i<nums.size() ; i++){
        //     for(int bits = 0 ; bits <= 31 ; bits++){
        //         if(nums[i] & (1 << bits)) freq[bits]++;
        //     }
        // }
        // int maxi = 0;
        // for(int i = 0 ; i<=31 ; i++) if(freq[i]) maxi |= (1 << i);
        int maxi = 0;
        for(int i = 0 ; i<nums.size() ; i++){
            maxi |= nums[i];
        }
        doit(0 , nums , maxi , 0);
        return count;
    }
};