class Solution
{
    public:
        double myPow(double x, int n)
        {
            double res = 1;
            long abs_n = abs(n);
            while (abs_n > 0)
            {
                if ((abs_n & 1) == 1)
                    res *= x;
                abs_n >>= 1;
                x *= x;
            }
            return n < 0 ? 1 / res : res;
        }
};
