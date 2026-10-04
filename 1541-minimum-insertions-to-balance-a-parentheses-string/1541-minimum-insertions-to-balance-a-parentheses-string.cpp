class Solution {
public:
    int minInsertions(string s) {
        stack<int> open , adhura;
        string use = "";
        int i = 0;
        while(i < s.size()){
            if(s[i] == '(') use+='(';
            else if(i+1 < s.size() && s[i+1] == ')') {
                use+=')';
                i++;
            }
            else use+='|';
            i++;
        }
        int ans = 0;
        for(int i = 0 ; i<use.size() ; i++){
            if(use[i] == '('){
                open.push(i);
            }
            else if(use[i] == ')'){
                if(!open.empty()) open.pop();
                else ans+=1;
            }
            else adhura.push(i);
        }
        
        while(!open.empty() && !adhura.empty()){
            if(open.top() < adhura.top()){
                open.pop();
                adhura.pop();
                ans+=1;
            }
            else {
                ans+=2;
                open.pop();
            }
        }

        return ans + 2*(open.size() + adhura.size());
    }
};