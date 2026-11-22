class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxi = 0 , l = 0 , r = 0;
        vector<int> freq(256 , 0);
        while(r < s.size()){
            freq[s[r]]++;
            while(freq[s[r]] > 1){
                freq[s[l]]--;
                l++;
            }
            maxi = max(maxi , r-l+1);
            r++;
        }
        return maxi;
    }
};