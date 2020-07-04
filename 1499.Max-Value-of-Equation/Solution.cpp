class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>> pq;
        size_t n = points.size();
        int ans = INT_MIN;
        size_t i = 0, j = 0;
        for (; i < n; ++i) {
            for (; j < i; ++j) {
                pq.push({points[j][1] - points[j][0], points[j][0]});
            }
            while (!pq.empty() && (points[i][0] - pq.top().second) > k) {
                pq.pop();
            }
            if (!pq.empty()) {
                ans = max(ans, pq.top().first + points[i][0] + points[i][1]);
            }
        }
        return ans;
    }
};
