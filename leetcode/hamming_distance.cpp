class Solution
{
    public:
        int hammingDistance(int x, int y)
        {
            int ctr = 0;
            int diff = x ^ y;
            while (diff)
            {
                ctr += diff & 1;
                diff >>= 1;
            }
            return ctr;
        }
};
