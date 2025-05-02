class Solution {
public:
    int LCS(string s1, string s2)
    {
        int l1 = s1.size();
        int l2 = s2.size();
        vector<vector<int>>dp(l1+1, vector<int>(l2+1, 0));
        for(int i = 1 ; i <= l1 ; i++)
        {
            for(int j = 1 ; j <= l2 ; j++)
            {
                if(s1[i-1] == s2[j-1])
                   dp[i][j] = 1 + dp[i-1][j-1];
                else
                   dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
        return dp[l1][l2];
    }
    int minDistance(string word1, string word2) 
    {
        int n1 = word1.size();
        int n2 = word2.size();
        int val = LCS(word1, word2);
        return((n1 - val) + (n2 - val));
    }
};