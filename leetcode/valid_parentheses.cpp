class Solution
{
    public:
        bool isValid(string s)
        {
            stack<char> opening_brackets;
            for (int i = 0; i < s.length(); i++)
            {
                bool empty = !opening_brackets.size();
                switch (s[i])
                {
                    case '(' :
                    case '{' :
                    case '[' : opening_brackets.push(s[i]); break;
                    case ')' : if (opening_brackets.empty() || opening_brackets.top() != '(')
                                   return false;
                               else
                                   opening_brackets.pop();
                               break;
                    case '}' : if (opening_brackets.empty() || opening_brackets.top() != '{')
                                   return false;
                               else
                                   opening_brackets.pop();
                               break;
                    case ']' : if (opening_brackets.empty() || opening_brackets.top() != '[')
                                   return false;
                               else
                                   opening_brackets.pop();
                               break;
                }
            }
            return opening_brackets.empty();
        }
};
