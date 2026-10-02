class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();

        vector<long long> prefix(2 * n + 1, 0);

        for (int i = 0; i < 2 * n; i++) {
            prefix[i + 1] = prefix[i] + nums[i % n];
        }

        deque<int> dq;
        dq.push_back(0);

        long long ans = LLONG_MIN;

        for (int r = 1; r <= 2 * n; r++) {

            // Remove starting positions that would
            // make the subarray length > n
            while (!dq.empty() && dq.front() < r - n)
                dq.pop_front();

            // Best start = smallest prefix sum
            ans = max(ans, prefix[r] - prefix[dq.front()]);

            // Maintain increasing prefix sums
            while (!dq.empty() && prefix[dq.back()] >= prefix[r])
                dq.pop_back();

            dq.push_back(r);
        }

        return (int)ans;
    }
};