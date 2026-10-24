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
        
        unordered_map<int , int> mpp = {
            {0 , 0},
            {1 , 31},
            {2 , 28},
            {3 , 31},
            {4 , 30},
            {5 , 31},
            {6 , 30},
            {7 , 31},
            {8 , 31},
            {9 , 30},
            {10 , 31},
            {11 , 30},
            {12 , 31}
        };


        vector<int> use = {
            0, 31, 59, 90, 120, 151,
            181, 212, 243, 273, 304, 334
        };

pair<int , int> alice = {use[alicearriveMonth-1] + alicearriveDay , use[aliceleaveMonth-1] + aliceleaveDay};

pair<int , int> bob = {use[bobarriveMonth-1]  +  bobarriveDay  , use[bobleaveMonth-1] + bobleaveDay};


        // if(alice.first > bob.second ||  bob.first > alice.second) return 0;

        // if(alice.first >= bob.first && alice.second <= bob.second) return alice.second - alice.first + 1;

        // if(bob.first >= alice.first && bob.second <= alice.second) return bob.second - bob.first + 1;



        // if(bob.first <= alice.second) return alice.second - bob.first + 1;

        // if(alice.first <= bob.second) return bob.second - alice.first + 1;
        
        int start = max(alice.first, bob.first);
int end = min(alice.second, bob.second);

return max(0, end - start + 1);

        return 0;
    }
};