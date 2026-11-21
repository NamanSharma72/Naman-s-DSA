class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string , int> mpp;
        for(int i = 0 ; i<wordList.size() ; i++) mpp[wordList[i]]++;
        queue<pair<string , int>> qt;
        qt.push({beginWord , 1});
        mpp.erase(beginWord);
        while(!qt.empty()){
            auto [currStr , currCount] = qt.front();
            qt.pop();
            if(currStr == endWord) return currCount;
            for(int i = 0 ; i<currStr.size() ; i++){
                int originalChar = currStr[i];
                for(char j = 'a' ; j <='z' ; j++){
                    currStr[i] = j;
                    if(mpp.find(currStr) != mpp.end()){
                        qt.push({currStr , currCount+1});
                        mpp.erase(currStr);
                    }
                }
                currStr[i] = originalChar;
            }
        }
        return 0;
    }
};