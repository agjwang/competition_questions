class Solution
{
    public:
        int strStr(string haystack, string needle)
        {
            int right_most[256] = {-1};
            for (int i = 0; i < needle.size(); i++)
                right_most[needle[i]] = i;

            int h = haystack.size();
            int n = needle.size();
            int skip ;
            for (int i = 0; i <= h - n; i += skip)
            {
                skip = 0;
                for (int j = n; j --> 0; )
                {
                    if (needle[j] != haystack[i + j])
                    {
                        skip = 1 > j - right_most[needle[j]] ? 1 : j - right_most[needle[j]];
                        break;
                    }
                }
                if (skip == 0)
                    return i;
            }
            return -1;
        }
};
