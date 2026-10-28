class Solution {
public:
    string reorganizeString(string s) {
        priority_queue<pair<int , char>> qt;
        vector<int> freq(26 , 0);
        for(int i = 0 ; i<s.size() ; i++) freq[s[i]-'a']++;
        for(int i = 0 ; i<26 ; i++){
            if(freq[i] > 0) qt.push({freq[i] , i+'a'});
        }
        // while(!qt.empty()){
        //     cout << qt.top().first << " " << qt.top().second << endl;
        //     qt.pop();
        // }
        string ans = "";
        for(int i = 0; i<s.size() ; i++){
            if(i == 0){
                pair<int , char> tope = qt.top();
                qt.pop();
                ans+=tope.second;
                tope.first--;
                if(tope.first > 0) qt.push(tope);
            }
            else{
                if(qt.top().second != ans[i-1]){
                     pair<int , char> tope = qt.top();
                        qt.pop();
                        ans+=tope.second;
                        tope.first--;
                        if(tope.first > 0) qt.push(tope);
                }
                else{
                    if(qt.size() == 1) return "";
                    pair<int , char> tope = qt.top();
                    qt.pop();
                    pair<int , char> secondtope = qt.top();
                    qt.pop();
                    ans+=secondtope.second;
                    secondtope.first--;
                    if(secondtope.first > 0) qt.push(secondtope);
                    qt.push(tope);
                }
            }
        }
        return ans;
    }
};