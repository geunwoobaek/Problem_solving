# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def dfs(self, res: int, node: TreeNode) -> int:
        if not node:
            return res
        cur_res = max(res+node.val, node.val)
        left_val = self.dfs(cur_res, node.right)
        right_val = self.dfs(cur_res, node.left)
        if (left_val < 0 or right_val < 0):
            return max(left_val, right_val)
        else return max()

    def maxPathSum(self, root: TreeNode) -> int:
        return self.dfs(0, root)


node = TreeNode()
solution = Solution()
print(solution.maxPathSum(node))
