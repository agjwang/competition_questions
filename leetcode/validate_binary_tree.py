# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def isValidBST(self, root, lessThan = float("inf"), greaterThan = float("-inf")):
        """
        :type root: TreeNode
        :rtype: bool
        """
        if not root:
            return true
        elif root.val <= greaterThan or root.val >= lessThan:
            return false
        else:
            return self.isValidBST(root.left, root.val, greaterThan) and \
                self.isValidBST(root.right, lessThan, root.val)