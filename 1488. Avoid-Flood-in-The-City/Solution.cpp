class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        set<int> dry_days;
        unordered_map<int, int> rain_days;
        vector<int> ans(rains.size(), 1);
        for (size_t i = 0; i < rains.size(); ++i) {
            if (rains[i]) {
                ans[i] = -1;
                if (rain_days.find(rains[i]) != rain_days.end()) {
                    int pre_day = rain_days[rains[i]];
                    int cur_day = i;
                    auto lb = dry_days.lower_bound(pre_day);
                    if (lb == dry_days.end()) return {};
                    ans[*lb] = rains[i];
                    rain_days[rains[i]] = i;
                    dry_days.erase(lb);
                }
                else {
                    rain_days[rains[i]] = i;
                }
            }
            else {
                dry_days.insert(i);
            }
        }
        return ans;
    }
};
