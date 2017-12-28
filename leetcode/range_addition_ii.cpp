class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        for (int i = 0; i < ops.size(); i++)
        {
            m = ops[i][0] < m ? ops[i][0] : m;
            n = ops[i][1] < n ? ops[i][1] : n;
        }
        return m * n;
    }
};
