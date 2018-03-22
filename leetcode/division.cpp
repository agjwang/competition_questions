class Solution {
public:
    // modified restoring division algorithm
    int divide(int dividend, int divisor) {
        // check for corner cases
        if (divisor == 0 || (dividend == INT_MIN && divisor == -1))
            return INT_MAX;

        if (dividend == 0)
            return 0;

        unsigned int msb = 1<<31; 

        bool positive_ans = (dividend > 0 && divisor > 0) ||
            (dividend < 0 && divisor < 0);

        // do division on positive integers
        divisor = abs(divisor);
        dividend = abs(dividend);

        unsigned int twos_comp_div = unsigned(~divisor) + 1;
        unsigned int a = 0;
        unsigned int m = unsigned(dividend);

        for (int i = 0; i < 32; i++) {
            int most_sig_bit = (m & msb) ? 1 : 0;
            
            // bitshift a and m, store overflow into a's lsb
            a = (a<<1) + most_sig_bit;
            m <<= 1;
            
            a += twos_comp_div;
            if (a & msb) {
                // restore
                a += divisor;
            } else {
                m += 1;
            }
        }

        return positive_ans ? m : ~m + 1;
    }
};