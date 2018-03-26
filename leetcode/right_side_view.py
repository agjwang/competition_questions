# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def rightSideView(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        if not root:
            return []

        view = []
        self.rightSideViewHelper(root, view)
        return view

    def rightSideViewHelper(self, root, view, height = 0):
        if not root:
            return

        if len(view) == height:
            view.append(root.val)
        
        self.rightSideViewHelper(root.right, view, height + 1)
        self.rightSideViewHelper(root.left, view, height + 1)