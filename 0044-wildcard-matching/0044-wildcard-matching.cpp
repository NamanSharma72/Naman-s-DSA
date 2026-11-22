class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size()+1 , vector<int>(p.size()+1 , -1));
        for(int i = 0 ; i<=s.size() ; i++){
            if(i == s.size()) dp[i][p.size()] = true;
            else dp[i][p.size()] = false;
        }
        for(int pIdx = p.size()-1 ; pIdx >=0 ; pIdx--){
            for(int sIdx = s.size() ; sIdx >=0 ; sIdx--){
                bool result = false;
                if(sIdx < s.size() && (s[sIdx] == p[pIdx] || p[pIdx] == '?')){
                    result = dp[sIdx+1][pIdx+1];
                }
                else if(p[pIdx] == '*'){
                    result = dp[sIdx][pIdx+1] || (sIdx < s.size() && dp[sIdx+1][pIdx]);
                }
                dp[sIdx][pIdx] = result;
            }
        }
        return dp[0][0];
    }
};