#include <bits/stdc++.h>
using namespace std;
#define Key pair<TreeNode *, int>
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
enum
{
    ALL = 1,
    LEFT = 2,
    RIGHT = 3
};
map<Key, int> um;
int min_value = -2e9;
//dp[root][0]=cur+max(0,dp[root->left][1],dp[root->right][2]))
//+max(0,dp[root->right][1],dp[root->right][2]))
class Solution
{
public:
    int maxPathSum(TreeNode *root)
    {
        dfs(root, ALL);
        for (auto &it : um)
        {
            cout << it.second << "\n";
            min_value = max(it.second, min_value);
        }
        um.clear();
        return min_value;
    }
    int dfs(TreeNode *cur, int How) //cur 노드 부터 시작
    {
        Key now_key = {cur, How};
        if (um.find(now_key) != um.end()) return um[now_key];
        int left = -2e9, right = -2e9;
        if (cur->left != nullptr) left = max(dfs(cur->left, LEFT), dfs(cur->left, RIGHT));
        if (cur->right != nullptr) right = max(dfs(cur->right, LEFT), dfs(cur->right, RIGHT));
        um[{cur, ALL}] = cur->val + max(left, 0) + max(right, 0);
        um[{cur, LEFT}] = cur->val + max(left, 0);
        um[{cur, RIGHT}] = cur->val + max(right, 0);
        return um[{now_key}];
    };
    int dfs2(TreeNode* node) {
        if (node == nullptr) return 0;
        int left = max(0, dfs2(node->left));
        int right = max(0, dfs2(node->right));
        min_value = max(min_value, left + right + node->val);
        return max(left, right) + node->val;
    }
};
int main()
{
    TreeNode *treenode = new TreeNode(0);
    treenode->right = new TreeNode(2);
    treenode->left = new TreeNode(3);
    Solution *s = new Solution();
    s->maxPathSum(treenode);
}