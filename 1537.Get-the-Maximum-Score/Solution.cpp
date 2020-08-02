class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        vector<long long> dp1(n1 + 1, 0), dp2(n2 + 1, 0);
        int j1 = n1 - 1, j2 = n2 - 1;
        int mod = 1e9 + 7;
        while (j1 >= 0 && j2 >= 0) {
            while (j1 >= 0 && j2 >= 0 && nums1[j1] > nums2[j2]) {
                dp1[j1] = nums1[j1] + dp1[j1 + 1];
                j1--;
            }
            while (j2 >= 0 && j1 >= 0 && nums1[j1] < nums2[j2]) {
                dp2[j2] = nums2[j2] + dp2[j2 + 1];
                j2--;
            }
            if (j1 >= 0 && j2 >= 0 && nums1[j1] == nums2[j2]) {
                dp1[j1] = max(dp1[j1 + 1], dp2[j2 + 1]) + nums1[j1];
                dp2[j2] = dp1[j1];
                j1--;
                j2--;
            }
        }
        while (j1 >= 0) {
            dp1[j1] = nums1[j1] + dp1[j1 + 1];
            j1--;
        }
        while (j2 >= 0) {
            dp2[j2] = nums2[j2] + dp2[j2 + 1];
            j2--;
        }
        return max(dp1[0], dp2[0]) % mod;
    }
};
