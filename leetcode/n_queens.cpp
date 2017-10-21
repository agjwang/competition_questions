class Solution
{
    public:
        bool isSafe(vector<string> board, int row, int col, int n)
        {
            for (int i = 0; i < col; i++)
                if (board[row][i] == 'Q')
                    return false;

            for (int i = row - 1, j = col + 1; i >= 0 && j >= 0; j--, i--)
                if (board[i][j] == 'Q')
                    return false;

            for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
                if (board[i][j] == 'Q')
                    return false;

            return true;
        }

        void solveNQueensHelper(vector<vector<string>> &boards, vector<string> &board, int row, int n)
        {
            if (row == n)
            {
                boards.push_back(board);
                return;
            }

            for (int i = 0; i < n; i++)
            {
                if (isSafe(board, row, i, n))
                {
                    board[row][i] = 'Q';
                    solveNQueensHelper(boards, board, row + 1, n);
                    board[row][i] = '.';
                }
            }
        }

        vector<vector<string>> solveNQueens(int n)
        {
            vector<vector<string>> boards;
            vector<string> board(n, string(n, '.'));
            solveNQueensHelper(boards, board, 0, n);
            return boards;
        }
};
