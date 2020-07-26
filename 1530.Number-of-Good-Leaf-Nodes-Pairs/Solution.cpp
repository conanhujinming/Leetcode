/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int countPairs(TreeNode* root, int distance) {
        if (!root) return 0;
        if (distance < 2) return 0;
        ans = 0;
        dis = distance;
        dfs(root);
        return ans;
    }
    
private:
    vector<int> dfs(TreeNode* root) {
        vector<int> ret(dis, 0);
        if (!root) return ret;
        if (!root->left && !root->right) {
            ret[0] = 1;
            return ret;
        }
        auto left = dfs(root->left);
        auto right = dfs(root->right);
        vector<int> acc_left(dis, 0);
        acc_left[0] = left[0];
        for (int i = 1; i < dis; ++i) {
            acc_left[i] = acc_left[i - 1] + left[i];
        }
        vector<int> acc_right(dis, 0);
        acc_right[0] = right[0];
        for (int i = 1; i < dis; ++i) {
            acc_right[i] = acc_right[i - 1] + right[i];
        }
        for (int i = 0; i < dis - 1; ++i) {
            ans += left[i] * acc_right[dis - 2 - i];
        }
        for (int i = 1; i < dis; ++i) {
            ret[i] += left[i - 1] + right[i - 1];
        }
        return ret;
    }
    
    int ans = 0, dis;
};
