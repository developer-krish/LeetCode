class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) 
    {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> ans(m, vector<int>(n, 0));
        for(int i = 0 ; i < m ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                int cnt = 0;
                int dr[8] = {-1, -1, -1, 0, 0, 1, 1 ,1};
                int dc[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
                for(int k = 0 ; k < 8 ; k++)
                {
                    int nr = i + dr[k];
                    int nc = j + dc[k];
                    if(nr >= 0 && nr < m && nc >= 0 && nc < n)
                    {
                        if(board[nr][nc] == 1) cnt++;
                    }
                }
                if(board[i][j] == 1)
                {
                    if(cnt == 2 || cnt == 3)
                        ans[i][j] = 1;
                    else
                        ans[i][j] = 0;
                }
                else
                {
                    if(cnt == 3)
                        ans[i][j] = 1;
                    else
                        ans[i][j] = 0;
                }
            }
        }
        board = ans;
        return;
    }
};