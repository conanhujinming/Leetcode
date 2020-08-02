class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> nums(n);
        for (int i = 0; i < n; ++i) {
            int cnt = 0;
            for (int j = n - 1; j >= 0; --j) {
                if (grid[i][j]) break;
                cnt++;
            }
            nums[i] = cnt;   
        }
        int res = 0;
        for (int i = 0; i < n; ++i) {
            bool find = false;
            for (int j = i; j < n; ++j) {
                if (nums[j] >= (n - i - 1)) {
                    find = true;
                    res += j - i;
                    for (int k = j; k > i; --k) {
                        swap(nums[k], nums[k - 1]);
                    }
                    break;
                }
            }
            if (!find) return -1;
        }
        return res;
    }
};
