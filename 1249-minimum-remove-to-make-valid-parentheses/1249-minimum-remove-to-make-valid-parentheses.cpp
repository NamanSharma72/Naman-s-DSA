class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        st.push(-1);
        for(int i = 0 ; i<s.size() ; i++){
            if(s[i] == '(') st.push(i);
            else if(s[i] == ')'){
                st.pop();
                if(st.empty()){
                    s[i] = '?';
                    st.push(i);
                }
            }
        }
        while(!st.empty()){
            if(st.top() >= 0) s[st.top()] = '?';
            st.pop();
        }
        string ans = "";
        for(int i = 0 ; i<s.size() ; i++) if(s[i] != '?') ans+=s[i];
        return ans;
    }
};