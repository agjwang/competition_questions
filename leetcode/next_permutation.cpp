class Solution
{
    public:
        void nextPermutation(vector<int> &nums)
        {
            bool has_next_permutation = false;
            int swap_idx = -1;
            for (int i = nums.size(); i --> 1; )
            {
                if (nums[i] > nums[i - 1])
                {
                    has_next_permutation = true;
                    swap_idx = i;
                    break;
                }
            }
            
            if (has_next_permutation)
            {
                sort(nums.begin() + swap_idx, nums.end());
                int  min_idx = lower_bound(nums.begin() + swap_idx, 
                        nums.end(), nums[swap_idx - 1] + 1) - nums.begin();

                int temp = nums[min_idx];
                nums[min_idx] = nums[swap_idx - 1];
                nums[swap_idx - 1] = temp;
                sort(nums.begin() + swap_idx, nums.end());
            }
            else
                sort(nums.begin(), nums.end());
        }
};
