class Solution {
public:
    int maxValue(vector<vector<int>>& events, int m) 
    {
        sort(events.begin(), events.end(), [](const vector<int>& a, const vector<int>& b)
        {
            return a[0] < b[0];
        });
        int n = events.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        vector<int> startTime(n);
        for(int i = 0 ; i < n ; i++)
        {
            startTime[i] = events[i][0];
        }
        for(int i = n - 1 ; i >= 0 ; i--)
        {
            
            
           
            for(int j = 1 ; j <= m ; j++)
            {

                int notTake = dp[i+1][j];
                int next = upper_bound(startTime.begin(), startTime.end(), events[i][1]) - startTime.begin();
                
               
              
                  
               
                int take =events[i][2];
                if (next < n)
                    take += dp[next][j - 1];
                dp[i][j] = max(take, notTake);

            }
        }
        return dp[0][m];
        
    }
};