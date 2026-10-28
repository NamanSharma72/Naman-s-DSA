class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int , char>> qt;
        if(a > 0) qt.push({a, 'a'});
        if(b > 0) qt.push({b , 'b'});
        if(c > 0) qt.push({c , 'c'});
        string ans = "";
        while(!qt.empty()){
            if(ans.empty()){
                pair<int , char> tope = qt.top();
                qt.pop();
                ans+=tope.second;
                tope.first--;
                if(tope.first > 0) qt.push(tope);
            }
            else{
                pair<int , char> tope = qt.top();
                qt.pop();
                if(tope.second != ans.back() || (tope.second == ans.back() && (ans.size() == 1 || ans[ans.size()-2] != tope.second))){
                    ans+=tope.second;
                    tope.first--;
                    if(tope.first > 0) qt.push(tope);
                    continue;
                }
                if(qt.empty()) break;
                pair<int , char> secondtope = qt.top();
                qt.pop();
                if(secondtope.second != ans.back() || (secondtope.second == ans.back() && (ans.size() == 1 || ans[ans.size()-2] != secondtope.second))){
                    ans+=secondtope.second;
                    secondtope.first--;
                    if(secondtope.first > 0) qt.push(secondtope);
                    qt.push(tope);
                    continue;
                }
                if(qt.empty()) break;
                pair<int , char> thirdtope = qt.top();
                qt.pop();
                if(thirdtope.second != ans.back() || (thirdtope.second == ans.back() && (ans.size() == 1 || ans[ans.size()-2] != thirdtope.second))){
                    ans+=thirdtope.second;
                    thirdtope.first--;
                    if(thirdtope.first > 0) qt.push(thirdtope);
                    qt.push(secondtope);
                    qt.push(tope);
                    continue;
                }
                if(qt.empty()) break;
            }
        }
        return ans;
    }
};