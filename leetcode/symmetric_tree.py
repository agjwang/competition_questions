# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def isSymmetric(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        if not root:
            return True
        else:
            return self.isSymmetricHelper(root.left, root.right)
        
    def isSymmetricHelper(self, left, right):
        if (left and not right) or (right and not left):
            return False
        elif not left and not right:
            return True
        elif left.val != right.val:
            return False
        else:
            return self.isSymmetricHelper(left.left, right.right) and \
                self.isSymmetricHelper(left.right, right.left)