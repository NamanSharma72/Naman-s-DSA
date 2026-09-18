class Solution {
public:
    int dp[2001][4];
    bool doit(int idx , int k , string &s , vector<vector<bool>> &isPal){
        if(idx == s.size()){
            if(k == 3) return true;
            return false;
        }
        if(k > 3) return false;
        if(dp[idx][k] != -1) return dp[idx][k];
        bool ans = false;
        for(int i = idx ; i<s.size() ; i++){
            if(isPal[idx][i]){
                bool use = doit(i+1 , k+1 , s , isPal);
                ans = ans || use;
            }
        }
        return dp[idx][k] = ans;
    }
    bool checkPartitioning(string s) {
        vector<vector<bool>> isPal(s.size() , vector<bool>(s.size() , false));
        for(int i = 0 ; i<s.size() ; i++){
            int left = i , right = i;
            while(left >= 0 && right < s.size()){
                if(s[left] == s[right]) isPal[left][right] = true;
                else break;
                left--;
                right++;
            }
            if(i+1 >= s.size()) continue;
            int left1 = i , right1 = i+1;
            while(left1 >=0 && right1 < s.size()){
                if(s[left1] == s[right1]) isPal[left1][right1] = true;
                else break;
                left1--;
                right1++;
            }
        }
        memset(dp , -1 , sizeof(dp));
        return doit(0 , 0 , s , isPal);
    }
};