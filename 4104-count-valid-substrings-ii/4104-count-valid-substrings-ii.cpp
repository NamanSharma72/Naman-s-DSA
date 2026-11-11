class Solution {
public:
    long long countValidSubstrings(string s) {
        vector<int> mpp(s.size() , -1);
        int lastA = -1;
        int l = 0, r=0;
        long long ans = 0;
        int lastB = -1;
        while(r < s.size()){
            if(s[r] == 'a') lastA = r;
            if(s[r] == 'b') {
                lastB = r;
                mpp[lastB] = lastA;
            }
            if(s[r] == 'c' && lastB >= l && mpp[lastB] >= l) l = mpp[lastB]+1;
            ans+=(r-l+1);
            r++;
        }
        return ans;
    }
};