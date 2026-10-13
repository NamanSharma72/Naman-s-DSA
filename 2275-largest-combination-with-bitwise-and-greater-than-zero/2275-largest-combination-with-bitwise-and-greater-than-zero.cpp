class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int> freq(32 , 0);
        for(int i = 0 ; i<candidates.size() ; i++){
            for(int bit = 0 ; bit <= 31 ; bit++){
                if(candidates[i] & (1 << bit)) freq[bit]++;
            }
        }
        int ans = 0;
        for(int i = 0 ; i<32 ; i++) ans = max(ans , freq[i]);
        return ans;
    }
};