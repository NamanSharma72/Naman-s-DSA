class Solution {
public:
    int scoreOfParentheses(string s) {
        int ans = 0;
        stack<int> st;
        for(int i = 0 ; i<s.size() ; i++){
            if(s[i] == '(') st.push(-1);
            else{
                int points = 0;
                while(!st.empty() && st.top() != -1) {
                    points+=st.top();
                    st.pop();
                }
                if(!st.empty()) st.pop();
                if(st.empty()) {
                    if(points == 0) ans+=1;
                    else ans+=(2*points);
                }
                else if(points == 0) st.push(1);
                else st.push(2*points);
            }
        }
        return ans;
    }
};