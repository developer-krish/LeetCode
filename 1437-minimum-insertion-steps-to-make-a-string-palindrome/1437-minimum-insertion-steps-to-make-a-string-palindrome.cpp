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
    int minInsertions(string s) 
    {
        string t = s;
        reverse(t.begin(), t.end());
        int n = s.size();
        return n - LCS(s, t); 
        // number of insertion(length thode thode character of string which is not involved in making string palindromic) = length of string - maximum number of palindromic subseq
    }
};