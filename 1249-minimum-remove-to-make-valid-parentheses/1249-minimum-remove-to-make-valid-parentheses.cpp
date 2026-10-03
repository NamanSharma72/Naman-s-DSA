class Solution {
public:
    string minRemoveToMakeValid(string s) {
        unordered_set<int> st;
        for(int i = 0 ; i<s.size() ; i++) if(s[i] == '(' || s[i] == ')') st.insert(i);
        int open = 0 , close = 0;
        for(int i = 0 ; i<s.size() ; i++){
            if(s[i] == '(' && st.count(i)) open++;
            if(s[i] == ')' && st.count(i)) close++;
            if(close > open){
                close = open = 0;
                st.erase(i);
            }
        }
        open = 0 , close = 0;
        for(int i = s.size()-1 ; i>=0 ; i--){
            if(s[i] == '(' && st.count(i)) open++;
            if(s[i] == ')' && st.count(i)) close++;
            if(open > close){
                close = open = 0;
                st.erase(i);
            }
        }
        string ans = "";
        for(int i = 0 ; i<s.size() ; i++){
            if(s[i] == '(' || s[i] == ')'){
                if(st.count(i)) ans+=s[i];
            }
            else ans+=s[i];
        }
        return ans;
    }
};