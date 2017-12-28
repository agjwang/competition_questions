class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows < 2 || s.size() <= numRows)
            return s;

        string ret = "";
        for (int i = 0; i < numRows; i++)
        {
            if (i == 0 || i == numRows - 1)
                for (int j = i; j < s.size(); j += 2 * (numRows - 1))
                    ret += s[j];
            else
                for (int j = i, k = 2 * i; j < s.size(); k = 2 * (numRows - 1) - k, j += k)
                    ret += s[j];
        } 
        return ret;
    }
};
