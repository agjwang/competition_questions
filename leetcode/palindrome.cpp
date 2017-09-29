class Solution
{
    public:
        bool isPalindrome(int x)
        {
            if (x < 0)
                return false;

            string str = to_string(x);
            while(str.length())
            {
                if (str[0] != str[str.length() - 1])
                    return false;
                str = str.substr(1, str.length() - 2);
            }
            return true;
        }
};
