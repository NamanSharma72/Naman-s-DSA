class Solution {
public:
    int maxSubarray(vector<int>& nums) {
        int maxi = 0;
        for(int i = 0 ; i<nums.size() ; i++){
            vector<int> freq(501 , 0);
            vector<int> namu(501 , 0);
            for(int j = i ; j<nums.size() ; j++){
                if(freq[nums[j]]) break;
                namu[nums[j]]++;
                int flag = 0;
                for(int k = i ; k < j ; k++) {
                    if((nums[j] + nums[k] <= 500)) {
                        if(namu[nums[j]+nums[k]]){
                            flag = 1;
                            break;
                        }
                        freq[nums[j] + nums[k]]++;
                    }
                }
                if(flag == 1) break;
                maxi = max(maxi , j-i+1);
                // int flag = 0;
                // for(int k = 1 ; k<=500 ; k++){
                //     if(freq[k] != 0 && namu[k] != 0){
                //         flag = 1;
                //         break;
                //     }
                // }
            }
        }
        return maxi;
    }
};