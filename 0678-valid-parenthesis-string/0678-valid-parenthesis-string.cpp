class Solution {
public:
    bool checkValidString(string s) {
        stack<int> st;
        stack<int> star;
        for(int i = 0 ; i<s.size() ; i++){
            if(s[i] == '(') st.push(i);
            else if(s[i] == '*') star.push(i);
            else{
                if(!st.empty()) st.pop();
                else if(star.size() > 0) star.pop();
                else return false;
            }
        }
        while(!st.empty()){
            int open = st.top();
            int close;
            if(star.empty()) return false;
            else close = star.top();
            st.pop();
            star.pop();
            if(open > close) return false;
        }
        return true;
    }
};