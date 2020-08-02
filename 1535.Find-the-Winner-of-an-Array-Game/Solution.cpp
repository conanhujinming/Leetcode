class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int i = 0, j = 1, n = arr.size(), cnt = 0;
        while (1) {
            if (arr[i % n] > arr[j % n]) {
                cnt++;
                swap(arr[i % n], arr[j % n]);
                i++, j++;
            }
            else {
                cnt = 1;
                i++, j++;
            }
            if (cnt == k || cnt == n) return arr[i % n];
        }
        return -1;
    }
};
