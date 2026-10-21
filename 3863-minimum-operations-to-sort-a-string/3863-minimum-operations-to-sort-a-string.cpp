class Solution {
public:
    int minOperations(string s) {
        char mini = s[0] , maxi = s[0];
        for(int i = 0 ; i<s.size() ; i++){
            if(s[i] < mini) mini = s[i];
            if(s[i] > maxi) maxi = s[i];
        }
        if(s.size() == 2){
            if(s[0] == mini) return 0;
            return -1;
        }
        int flag = 0;
        for(int i = 1 ; i<s.size() ; i++){
            if(s[i] < s[i-1]){
                flag = 1;
                break;
            }
        }
        if(flag == 0) return 0;
        if(s[0] == mini || s[s.size()-1] == maxi) return 1;
        for(int i = 1 ; i<s.size()-1 ; i++){
            if(s[i] == maxi || s[i] == mini) return 2;
        }
        return 3;
    }
};