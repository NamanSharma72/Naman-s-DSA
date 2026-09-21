class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> answer(k , 0) , prevDp(k , 0);
        for(int i = 0 ; i<nums.size() ; i++){
            vector<long long> newDp(k , 0);
            int currRem = nums[i]%k;
            newDp[currRem]++;
            for(int r = 0 ; r<k ; r++){
                int newRem = (r * currRem)%k;
                newDp[newRem]+=prevDp[r];
            }
            for(int r = 0 ; r<k ; r++) answer[r]+=newDp[r];
            prevDp = newDp;
        }
        return answer;
    }
};