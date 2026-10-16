class Solution {
public:
    int dp[501][501];
    int doit(int idx1 , int idx2 , string &word1 , string &word2){
        if(idx2 == word2.size()){
            return word1.size() - idx1;
        }
        if(dp[idx1][idx2] != -1) return dp[idx1][idx2];
        int insert = 1 + doit(idx1 , idx2+1 , word1 , word2);
        int del = 1e9;
        if(idx1 < word1.size()) del = 1 + doit(idx1+1 , idx2 , word1 , word2);
        int rep = 1e9;
        if(idx1 < word1.size()) rep = 1 + doit(idx1+1 , idx2+1 , word1 , word2);
        int same = 1e9;
        if(idx1 < word1.size() && word1[idx1] == word2[idx2]) same = doit(idx1+1 , idx2+1 , word1 , word2);

        return dp[idx1][idx2] = min(min(insert , del) , min(rep , same));

    }
    int minDistance(string word1, string word2) {
        cout << word1.size();
        memset(dp , -1 , sizeof(dp));
        return doit(0 , 0 , word1 , word2);
    }
};