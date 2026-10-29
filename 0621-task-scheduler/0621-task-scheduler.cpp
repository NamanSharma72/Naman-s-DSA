class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26 , 0);
        for(int i = 0 ; i<tasks.size() ; i++) freq[tasks[i]-'A']++;
        priority_queue<pair<int , char>> qt;
        for(int i = 0 ; i<26 ; i++){
            if(freq[i] > 0) qt.push({freq[i] , i + 'A'});
        }
        queue<pair<int , pair<int , char>>> qu;
        int timer = 0;
        while(!qt.empty() || !qu.empty()){
            if(!qt.empty()){
                pair<int , char> tope = qt.top();
                qt.pop();
                tope.first--;
                if(tope.first > 0) qu.push({timer+n+1 , tope});
            }
            timer++;
            if(!qu.empty() && qu.front().first == timer){
                qt.push(qu.front().second);
                qu.pop();
            }
        }
        return timer;
    }
};