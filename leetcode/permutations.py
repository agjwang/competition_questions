class Solution(object):
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        permutations = []
        for i, n in enumerate(nums):
            # permutations of subarray
            for p in self.permute(nums[:i] + nums[i + 1:]):
                permutations = permutations + [[n] + p]
        return permutations or [[]]