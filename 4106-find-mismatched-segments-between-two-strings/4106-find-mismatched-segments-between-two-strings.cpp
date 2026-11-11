class Solution {
public:
    vector<vector<string>> findMismatchedSegments(string s1, string s2) {
        vector<vector<string>> ans;
        int r = 0;
        string st1 = "" , st2 = "";
        while(r < s1.size()){
            if(s1[r] == s2[r]){
                if(!st1.empty()) ans.push_back({st1 , st2});
                st1 = "";
                st2 = "";
            }
            else{
                st1+=s1[r];
                st2+=s2[r];
            }
            r++;
        }
        if(!st1.empty()) ans.push_back({st1 , st2});
        return ans;
    }
};