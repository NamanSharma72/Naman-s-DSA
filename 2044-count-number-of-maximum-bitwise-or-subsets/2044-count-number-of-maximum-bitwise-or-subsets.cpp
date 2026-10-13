class Solution {
public:
    int doit(int idx , vector<int>& nums , int maxi , int xo){
        if(idx == nums.size()){
            if(xo == maxi) return 1;
            return 0;
        }
        int take = 0;
        take+=doit(idx+1 , nums , maxi , xo | nums[idx]);
        int skip = 0;
        skip+=doit(idx+1 ,  nums , maxi , xo);
        return take + skip;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int maxi = 0;
        for(int i = 0 ; i<nums.size() ; i++) maxi |= nums[i];
        int count = doit(0 , nums , maxi , 0);
        return count;
    }
};