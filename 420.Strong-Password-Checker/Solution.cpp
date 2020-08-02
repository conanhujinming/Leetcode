class Solution {
public:
    int strongPasswordChecker(string s) {
        int lw = 0, up = 0, di = 0;
        for (auto chr:s) {
            lw += (chr >= 'a') && (chr <= 'z');
            up += (chr >= 'A') && (chr <= 'Z');
            di += (chr >= '0') && (chr <= '9');
        }
        int missing = 3 - (lw != 0) - (up != 0) - (di != 0);
        int change = 0, one = 0, two = 0;
        int p = 2, len;
        while (p < s.size()) {
            if (s[p] == s[p - 1] && s[p] == s[p - 2]) {
                len = 2;
                while (p < s.size() && s[p] == s[p - 1]) {
                    len++;
                    p++;
                }
                change += len / 3;
                if (!(len % 3)) one += 1;
                else if ((len % 3) == 1) two += 1;
            }
            else p++;
        }
        if (s.size() < 6) return max(missing, 6 - (int)s.size());
        else if (s.size() <= 20) return max(missing, change);
        else {
            int de = s.size() - 20;
            change -= min(de, one);
            change -= min(max((de - one), 0), two * 2) / 2;
            change -= max(de - one - 2 * two, 0) / 3;
            return de + max(missing, change);
        }
        return -1;
    }
};
