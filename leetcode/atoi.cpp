class Solution 
{
    public:
        int myAtoi(string str)
        {
            long long res = 0;
            bool is_finished = false;
            bool is_negative = false;
            int i = str.find_first_not_of(' ');
            for (; i < str.length(); i++)
            {
                switch (str[i])
                {
                    case '+' : 
                        {
                            if (i != str.find_first_not_of(' '))
                               is_finished = true;
                            break;
                        }
                    case '-' :
                        {
                            if (i != str.find_first_not_of(' '))
                                is_finished = true;
                            else
                                is_negative = true;
                            break;
                        }
                    case '0' :
                    case '1' :
                    case '2' :
                    case '3' :
                    case '4' :
                    case '5' :
                    case '6' :
                    case '7' :
                    case '8' :
                    case '9' : res = res * 10 + str[i] % '0'; break;
                    default  : is_finished = true; break;
                } 

                long long test = is_negative ? res * -1 : res;
                if (test > INT_MAX)
                    return INT_MAX;
                if (test < INT_MIN)
                    return INT_MIN;

                if (is_finished)
                    break;
            }
            if (is_negative)
                res *= -1;
            return res;
        }
};
