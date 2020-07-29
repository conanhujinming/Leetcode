class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<int> hist(m, 0);
        int res = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                hist[j] = mat[i][j] ? hist[j] + 1 : 0;
            }
            res += countOneCol(hist);
        }
        return res;
    }
    
private:
    int countOneCol(const vector<int>& hist) {
        stack<int> st;
        vector<int> sum(hist.size(), 0);
        for (int i = 0; i < hist.size(); ++i) {
            while (!st.empty() && hist[st.top()] >= hist[i]) st.pop();
            if (!st.empty()) {
                int pre_index = st.top();
                sum[i] = sum[pre_index] + hist[i] * (i - pre_index);
            }
            else {
                sum[i] = hist[i] * (i + 1);
            }
            st.push(i);
        }
        return accumulate(sum.begin(), sum.end(), 0);
    }
};
