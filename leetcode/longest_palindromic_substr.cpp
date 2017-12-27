class Solution {
public:
    string expand(string s, int i, int j) {
        while(i >= 0 && j < s.length() && s[i] == s[j]) {
            i--;
            j++;
        }
        return s.substr(i + 1, j - i - 1);
    }

    string longestPalindrome(string s) {
        if (s.length() < 2)
            return s;

        string longest = s.substr(0, 1);

        for (int i = 0; i < s.length() - 1; i++) {
            string temp = expand(s, i, i);
            if (temp.length() > longest.length())
                longest = temp;
            temp = expand(s, i, i + 1);
            if (temp.length() > longest.length())
                longest = temp;
        }
        return longest;
    }
};
