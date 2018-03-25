class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        maxSum = nums[0]
        maxRollingSum = 0
        index = 0
        length = len(nums)

        while index < length:
            maxRollingSum += nums[index]
            maxSum = max(maxSum, maxRollingSum)
            maxRollingSum = max(maxRollingSum, 0)
            index += 1

        return maxSum