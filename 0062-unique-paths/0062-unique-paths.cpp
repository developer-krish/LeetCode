class Solution {
public:
    int uniquePaths(int m, int n) 
    {
        vector <vector<int>> arr(m, vector<int>(n, 0));
        arr[0][0] = 1;
        for(int i = 0 ; i < m ; i++)
        {
            for(int j = 0 ; j < n ; j++)     
            {
                if(i == 0 && j == 0) arr[0][0] = 1;
                else
                {
                    int up = 0; 
                    int left = 0;
                    if(i > 0) up = arr[i-1][j];
                    if(j > 0) left = arr[i][j-1];
                    arr[i][j] = up + left;
                } 
            }
        }
        return arr[m-1][n-1];
    }
};