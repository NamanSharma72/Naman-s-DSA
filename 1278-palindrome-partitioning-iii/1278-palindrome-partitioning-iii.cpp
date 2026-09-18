class Solution {
public:
    int dp[100][101];
    int doit(int idx , int k , vector<vector<int>> &makePal){
        if(idx == makePal.size()){
            if(k == 0) return 0;
            return 1e9;
        }
        if(k < 0) return 1e9;
        if(dp[idx][k] != -1) return dp[idx][k];
        int mini = 1e9;
        for(int i = idx ; i<makePal.size() ; i++){
            int ans = makePal[idx][i] + doit(i+1 , k-1 , makePal);
            mini = min(mini , ans);
        }
        return dp[idx][k] = mini;
    }
    int palindromePartition(string s, int k) {
        vector<vector<int>> makePal(s.size() , vector<int>(s.size()));
        for(int i = 0 ; i<s.size() ; i++){
            int left = i , right = i;
            int needed = 0;
            while(left >= 0 && right < s.size()){
                if(s[left] != s[right]) needed++;
                makePal[left][right] = needed;
                left--;
                right++;
            }
        }
        for(int i = 0 ; i<s.size()-1 ; i++){
            int left = i , right = i+1;
            int needed = 0;
            while(left >= 0 && right < s.size()){
                if(s[left] != s[right]) needed++;
                makePal[left][right] = needed;
                left--;
                right++;
            }
        }
        memset(dp , -1 , sizeof(dp));
        return doit(0 , k , makePal);
    }
};