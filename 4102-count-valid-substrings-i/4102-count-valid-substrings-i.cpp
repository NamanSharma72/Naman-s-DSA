class Solution {
public:
    long long countValidSubstrings(string s) {
        int l = 0 , r = 0;
        long long ans = 0;
        while(r < s.size()){
            if(s[r] == 'c' && (r-2 >=0 && s[r-2] == 'a' && s[r-1] == 'b')) l = r-1;
            ans+=(r-l+1);
            r++;
        }
        return ans;
    }
};