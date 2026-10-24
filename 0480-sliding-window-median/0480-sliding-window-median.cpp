
class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int> left, right;
        vector<double> ans;
        auto balance = [&]() {
            while (left.size() > right.size() + 1) {
                right.insert(*left.rbegin());
                left.erase(prev(left.end()));
            }
            while (left.size() < right.size()) {
                left.insert(*right.begin());
                right.erase(right.begin());
            }
        };
        for (int r = 0; r < nums.size(); r++) {
            if (left.empty() || nums[r] <= *left.rbegin()) {
                left.insert(nums[r]);
            } else {
                right.insert(nums[r]);
            }
            balance();
            // Remove the element that leaves the window.
            if (r >= k) {
                int outgoing = nums[r - k];
                auto it = left.find(outgoing);
                if (it != left.end()) left.erase(it);  // Erase only one occurrence.
                else right.erase(right.find(outgoing));
                balance();
            }
            // Calculate the median once the window is full.
            if (r >= k - 1) {
                if (k % 2 == 1) {
                    ans.push_back((double)*left.rbegin());
                } else {
                    double median =
                        ((double)*left.rbegin() + *right.begin()) / 2.0;

                    ans.push_back(median);
                }
            }
        }
        return ans;
    }
};
