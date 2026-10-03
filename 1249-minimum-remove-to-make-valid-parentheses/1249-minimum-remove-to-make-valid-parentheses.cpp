class Solution {
public:
    string minRemoveToMakeValid(string s) {
        // unordered_set<int> st;
        // for(int i = 0 ; i<s.size() ; i++) if(s[i] == '(' || s[i] == ')') st.insert(i);
        int open = 0 , close = 0;
        for(int i = 0 ; i<s.size() ; i++){
            if(s[i] == '(') open++;
            if(s[i] == ')') close++;
            if(close > open){
                close = open = 0;
                // st.erase(i);
                s[i] = '?';
            }
        }
        open = 0 , close = 0;
        for(int i = s.size()-1 ; i>=0 ; i--){
            if(s[i] == '(') open++;
            if(s[i] == ')') close++;
            if(open > close){
                close = open = 0;
                // st.erase(i);
                s[i] = '?';
            }
        }
        string ans = "";
        for(int i = 0 ; i<s.size() ; i++){
            if(s[i] != '?') ans+=s[i];
        }
        return ans;
    }
};