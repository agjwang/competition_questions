class Solution
{
    public:
        bool isSafe(int **board, int row, int col, int n)
        {
            for (int i = 0; i < row; i++)
                if (board[i][col] == 1)
                    return false;
            for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
                if (board[i][j] == 1)
                    return false;
            for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
                if (board[i][j] == 1)
                    return false;
            return true;
        }

        void nQueensHelper(int **board, int row, int &total, int n)
        {
            if (row == n)
            {
                total++;
                return;
            }

            for (int i = 0; i < n; i++)
            {
                if (isSafe(board, row, i, n))
                {
                    board[row][i] = 1;
                    nQueensHelper(board, row + 1, total, n);
                    board[row][i] = 0;
                }
            }
        }

        int totalNQueens(int n)
        {
            int total = 0;
            
            int **board = new int*[n];
            for (int i = 0; i < n; i++)
                board[i] = new int[n];

            nQueensHelper(board, 0, total, n);

            for (int i = 0; i < n; i++)
                delete[] board[i];
            delete board;

            return total;
        }
};
