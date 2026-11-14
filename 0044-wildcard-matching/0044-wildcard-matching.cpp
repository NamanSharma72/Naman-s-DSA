class Solution {
public:
    int dp[2001][2001];
    bool doit(int sIdx , int pIdx , string &s , string &p){
        if(pIdx == p.size()){
            return sIdx == s.size();
        }
        if(dp[sIdx][pIdx] != -1) return dp[sIdx][pIdx];
        bool find = false;
        if(s[sIdx] == p[pIdx] || p[pIdx] == '?'){
            find = find || doit(sIdx+1 , pIdx+1 , s, p);
        }
        else if(p[pIdx] == '*'){
            bool result = doit(sIdx , pIdx+1 , s , p) || ( sIdx < s.size() && doit(sIdx+1 , pIdx , s, p));
            find = find || result;
        }
        return dp[sIdx][pIdx] = find;
    }
    bool isMatch(string s, string p) {
        memset(dp , -1 , sizeof(dp));
        return doit(0 , 0 , s , p);
    }
};