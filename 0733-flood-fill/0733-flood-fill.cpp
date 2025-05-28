class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
    {
        int m = image.size();
        int n = image[0].size();
        vector<vector<int>> vis(m, vector<int>(n,0));
        queue <pair<int, int>> q;
        // for(int i = 0 ; i < m ; i++)
        // {
        //     for(int j = 0 ; j < n ; j++)
        //     {
        //         if(i == sr && j == sc)
        //         {
        //             vis[sr][sc] = 1;
        //             q.push({sr, sc});
        //         }
        //     }
        // }
        vis[sr][sc] = 1;
        q.push({sr, sc});
        int clr = image[sr][sc];
        image[sr][sc] = color;
        while(!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            int dRow[] = {-1, 0, 1, 0};
            int dCol[] = {0, 1, 0, -1};
            for(int i = 0 ; i < 4 ; i++)
            {
                int nRow = r + dRow[i];
                int nCol = c + dCol[i];
                if(nRow >= 0 && nRow < m && nCol >= 0 && nCol < n && vis[nRow][nCol] == 0 && clr == image[nRow][nCol])
                {
                    
                    image[nRow][nCol] = color;
                    q.push({nRow, nCol});
                    vis[nRow][nCol] = 1;
                }
            }
        }
        return image;

        
    }
};