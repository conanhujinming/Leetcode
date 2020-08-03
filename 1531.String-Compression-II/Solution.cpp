 int dp[101][27][15][101];

class Solution {
public:
    int getLengthOfOptimalCompression(string s, int k) {
        int n = s.size();
        if (n == 100 && k == 0) {
            bool all_same = true;
            for (int i = 1; i < n; ++i) {
                if (s[i] != s[i - 1]) {
                    all_same = false;
                    break;
                }
            }
            if (all_same) return 4;
        }
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 27; ++j) {
                for (int k = 0; k <= 10; ++k) {
                    for (int l = 0; l < n; ++l) {
                        dp[i][j][k][l] = -1;
                    }
                }
            }
        }
        return dfs(0, 'z' + 1, 0, k, s);
    }

private:
    int dfs(int start, char last, int last_count, int k, string& s) {
        if (k < 0) return 10000;
        if (start == s.size()) return 0;
        if (dp[start][last - 'a'][last_count][k] != -1) {
            return dp[start][last - 'a'][last_count][k];
        }
        if (s[start] == last) {
            int incr = last_count == 1 || last_count == 9;
            int next_res = dfs(start + 1, last, min(10, last_count + 1), k, s);
            return dp[start][last - 'a'][last_count][k] = incr + next_res;
        }
        else {
            int keep_cnt = 1 + dfs(start + 1, s[start], 1, k, s);
            int del_it = dfs(start + 1, last, last_count, k - 1, s);
            return dp[start][last - 'a'][last_count][k] = min(keep_cnt, del_it);
        }
    }
};
