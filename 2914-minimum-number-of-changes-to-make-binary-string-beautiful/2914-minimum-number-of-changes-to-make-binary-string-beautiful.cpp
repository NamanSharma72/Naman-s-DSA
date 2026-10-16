class Solution {
public:
    int minChanges(string s) {
        int changes = 0;
        int count1 = 0 , count0 = 0;
        for(int i = 0 ; i<s.size() ; i++){
            if(s[i] == '1') count1++;
            else count0++;
            if((count1 + count0)%2 == 0){
                if(count1 == 1 && count0 == 1) changes++;
                count1 = count0 = 0;
            }
        }
        return changes;
    }
};