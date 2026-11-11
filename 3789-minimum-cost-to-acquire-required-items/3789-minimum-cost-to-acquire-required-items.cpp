class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long first = (1LL * cost1 * need1) + (1LL * cost2 * need2);
        long long second = 1LL * max(need1 , need2) * costBoth;
        long long third = 1LL * min(need1 , need2) * costBoth;
        if(need1 - min(need1 , need2) > 0 ) third = third + 1LL * (need1 - min(need1 , need2)) * cost1;
        if(need2 - min(need1 , need2) > 0 ) third = third + 1LL * (need2 - min(need1 , need2)) * cost2;
        return min(first , min(second , third));
    }
};