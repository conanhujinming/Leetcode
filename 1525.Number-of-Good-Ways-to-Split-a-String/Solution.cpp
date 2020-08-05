class Solution {
public:
    int numSplits(string s) {
        int left_ctr[26] = {0}, right_ctr[26] = {0};
        int left_num = 0, right_num = 0;
        for (int i = s.size() - 1; i >= 0; --i) {
            if (!right_ctr[s[i] - 'a']) {
                ++right_num;
            }
            ++right_ctr[s[i] - 'a'];
        }
        int res = 0;
        for (int i = 0; i < s.size(); ++i) {
            res += left_num == right_num;
            left_num += !left_ctr[s[i] - 'a'];
            ++left_ctr[s[i] - 'a'];
            --right_ctr[s[i] - 'a'];
            right_num -= !right_ctr[s[i] - 'a'];
        }
        return res;
    }
};
