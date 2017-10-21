class Solution
{
    public:
        string largestNumber(vector<int> &nums)
        {
            string str = "";
            vector<string> strs;
            for (int i = 0; i < nums.size(); i++)
                strs.push_back(to_string(nums[i]));
            sort(strs.begin(), strs.end(), [](string &s1, string &s2) {return s1 + s2 < s2 + s1;});

            for (int i = strs.size(); i --> 0 ; )
                str += strs[i];
            while (str.length() > 1 && str[0] == '0')
                str.erase(0, 1);
            return str;
        }
};
