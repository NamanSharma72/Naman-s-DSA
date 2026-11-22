class Solution {
public:
    int dp[2001][2001];
    bool doit(int sIdx , int pIdx , string &s , string &p){
        if(pIdx == p.size()) return sIdx == s.size();
        if(dp[sIdx][pIdx] != -1) return dp[sIdx][pIdx];
        bool answer = false;
        if(sIdx < s.size() && (s[sIdx] == p[pIdx] || p[pIdx] == '?')){
            answer = doit(sIdx+1 , pIdx+1 , s , p);
        }
        else if(p[pIdx] == '*') answer = doit(sIdx , pIdx+1 , s , p) || (sIdx < s.size() && doit(sIdx+1 , pIdx, s , p));
        return dp[sIdx][pIdx] = answer;
    }
    bool isMatch(string s, string p) {
        memset(dp , -1 , sizeof(dp));
        return doit(0 , 0 , s , p);
    }
};