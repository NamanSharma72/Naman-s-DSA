class Solution {
public:
    int dp[2000];
    int doit(int idx , vector<vector<bool>> &isPal , int n){
        if(idx == n) return 0;
        if(dp[idx] != -1) return dp[idx];
        int best = 1e9;
        for(int i = idx ; i<n ; i++){
            int ans = 0;
            if(isPal[idx][i]){
                ans = 1 + doit(i+1 , isPal , n);
                best = min(ans , best);
            }
        }
        return dp[idx] = best;
    }
    int minCut(string s) {
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
        return doit(0 , isPal , s.size())-1;
    }
};