class Solution {
public:
    int minFlips(string target) {
        int res = 0;
        char cur = '0';
        for (size_t i = 0; i < target.size(); ++i) {
            if (target[i] != cur) {
                res++;
                cur = target[i];
            }
        }
        return res;
    }
};
