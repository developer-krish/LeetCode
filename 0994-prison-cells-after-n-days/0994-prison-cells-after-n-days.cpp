class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) 
    {
        int m = min(n, 14);
        vector<vector<int>> v(m, vector<int>(8));
        v[0][0] = 0, v[0][7] = 0;
        for(int i = 1 ; i < 7 ; i++)
        {
            v[0][i] = (cells[i - 1] == cells[i + 1]);
        }
        
        for(int i = 1 ; i < m ; i++)
        {
            v[i][0] = 0, v[i][7] = 0;
            for(int j = 1 ; j < 7 ; j++)
            {
                v[i][j] = (v[i - 1][j - 1] == v[i - 1][j + 1]);
            }
        }
        return v[(n - 1) % 14];
    }
};