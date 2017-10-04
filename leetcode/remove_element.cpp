class Solution
{
    public:
        int removeElement(vector<int> &nums, int val)
        {
            sort(nums.begin(), nums.end());
            int first = -1, last = -1;
            for (int i = 0, n = nums.size(); i < n; i++)
            {
                if (nums[i] == val)
                {
                    if (first == -1)
                        first = i;
                    last = i;
                }
            }
            if (first == -1 || last == -1)
                return nums.size();
            else if (first == 0 && last == nums.size() - 1)
                nums.clear();
            else
                nums.erase(nums.begin() + first, nums.begin() + last + 1);
            return nums.size();
        }
};
