class Solution {
public:
    int maximumSwap(int num) {
        string use = to_string(num);
        vector<int> maxRight(use.size() , -1);
        int maxi = -1;
        int maxIndex = -1;
        for(int i = use.size()-1 ; i>=0 ; i--){
            maxRight[i] = maxIndex;
            if(use[i]-'0' > maxi) {
                maxi = use[i]-'0';
                maxIndex = i;
            }
        }
        string temp = use;
        // for(int i = 0 ; i<use.size() ; i++) cout << maxRight[i] << " ";
        for(int i = 0 ; i<use.size()-1 ; i++){
            swap(temp[i] , temp[maxRight[i]]);
            if(temp > use) use = temp;
            swap(temp[i] , temp[maxRight[i]]);
        }
        // cout << use;
        int answer = stoi(use);
        return answer;
    }
};