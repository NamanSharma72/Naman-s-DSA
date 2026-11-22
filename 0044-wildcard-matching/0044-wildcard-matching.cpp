class Solution {
public:
    bool isMatch(string s, string p) {
        // vector<vector<int>> dp(s.size()+1 , vector<int>(p.size()+1 , -1));
        vector<int> next(s.size()+1 , 0);
        vector<int> curr(s.size()+1 , 0);
        for(int i = 0 ; i<=s.size() ; i++){
            if(i == s.size()) next[i] = true;
            else next[i] = false;
        }
        for(int pIdx = p.size()-1 ; pIdx >=0 ; pIdx--){
            for(int sIdx = s.size() ; sIdx >=0 ; sIdx--){
                bool result = false;
                if(sIdx < s.size() && (s[sIdx] == p[pIdx] || p[pIdx] == '?')){
                    result = next[sIdx+1];
                }
                else if(p[pIdx] == '*'){
                    result = next[sIdx] || (sIdx < s.size() && curr[sIdx+1]);
                }
                curr[sIdx] = result;
            }
            swap(curr , next);
        }
        return next[0];
    }
};