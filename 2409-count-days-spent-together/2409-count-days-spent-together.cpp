class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int alicearriveMonth = stoi(arriveAlice.substr(0 , 2));
        int bobarriveMonth = stoi(arriveBob.substr(0 , 2));
        int alicearriveDay = stoi(arriveAlice.substr(3, 2));
        int bobarriveDay = stoi(arriveBob.substr(3, 2));
        int aliceleaveMonth = stoi(leaveAlice.substr(0 , 2));
        int bobleaveMonth = stoi(leaveBob.substr(0 , 2));
        int aliceleaveDay = stoi(leaveAlice.substr(3, 2));
        int bobleaveDay = stoi(leaveBob.substr(3, 2));
        vector<int> use = {
            0, 31, 59, 90, 120, 151,
            181, 212, 243, 273, 304, 334
        };
pair<int , int> alice = {use[alicearriveMonth-1] + alicearriveDay , use[aliceleaveMonth-1] + aliceleaveDay};

pair<int , int> bob = {use[bobarriveMonth-1]  +  bobarriveDay  , use[bobleaveMonth-1] + bobleaveDay};
        int start = max(alice.first, bob.first);
        int end = min(alice.second, bob.second);

return max(0, end - start + 1);

       
    }
};