class Solution {
public:
    bool canAliceWin(int n) {
        int toRemove = 10;
        // 1 means alice and 0 means bob
        int turn = 1;
        while(n > 0){
            if(n >= toRemove) n-=toRemove;
            else{
                if(turn == 1) return false;
                return true;
            }
            turn = turn == 1 ? 0 : 1;
            toRemove--;
        }
        if(turn == 1) return false;
        return true;
    }
};