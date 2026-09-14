class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        // // points of rectangle 1
        // pair<int , int> point1 = {rec1[0] , rec1[1]};
        // pair<int , int> point2 = {rec1[0] , rec1[3]};
        // pair<int , int> point3 = {rec1[2] , rec1[3]};
        // pair<int , int> point4 = {rec1[2] , rec1[1]};
        // cout << point1.first << " " << point1.second << endl;
        // cout << point2.first << " " << point2.second << endl;
        // cout << point3.first << " " << point3.second << endl;
        // cout << point4.first << " " << point4.second << endl;
        // if(point1.first > rec2[0] && point1.first < rec2[2] && point1.second > rec2[1] && point1.second < rec2[3]) return true;
        // if(point2.first > rec2[0] && point2.first < rec2[2] && point2.second > rec2[1] && point2.second < rec2[3]) return true;
        // if(point3.first > rec2[0] && point3.first < rec2[2] && point3.second > rec2[1] && point3.second < rec2[3]) return true;
        // if(point4.first > rec2[0] && point4.first < rec2[2] && point4.second > rec2[1] && point4.second < rec2[3]) return true;
        if(((rec1[2] <= rec2[0]) && (rec1[2] < rec2[2])) || ((rec2[0] < rec1[0]) && (rec2[2] <= rec1[0]))) return false;
        if(rec1[1] >= rec2[3] || rec1[3] <= rec2[1]) return false;
        return true;
    }
};