class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        if (nums.size() < 3)
            return false;

        int k = INT_MIN;
        int index = nums.size();

        for (int i = nums.size(); i --> 0;)
        {
            if (nums[i] < k) return true;

            while (index < nums.size() && nums[i] > nums[index])
               k = nums[index++];

            nums[--index] = nums[i];
        }
        return false;
    }
};
