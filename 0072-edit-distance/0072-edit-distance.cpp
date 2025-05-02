class Solution {
public:
    int minDistance(string word1, string word2) 
    {
        int l1 = word1.size();
        int l2 = word2.size();
        vector<vector<int>> dp(l1+1, vector<int>(l2+1, 0));
        for(int j = 0 ; j <= l2 ; j++) dp[0][j] = j; // as j+1 is reduced to j , due to +1 of indexing.
        for(int i = 0 ; i <= l1 ; i++) dp[i][0] = i;
        for(int i = 1 ; i <= l1 ; i++)
        {
            for(int j = 1 ; j <= l2 ; j++)
            {
                if(word1[i-1] == word2[j-1])
                   dp[i][j] = dp[i-1][j-1];
                else
                   dp[i][j] = 1 + min({dp[i][j-1], dp[i-1][j], dp[i-1][j-1]});
            }
        }
        return dp[l1][l2];
    }
};

// memo
// class Solution {
// public:
//     int func(int i, int j , string s1, string s2, vector<vector<int>>& dp)
//     {
//         if(i < 0) return j+1;
//         if(j < 0) return i+1;
//         if(dp[i][j] != -1) return dp[i][j];
//         if(s1[i] == s2[j])
//            return func(i-1, j-1, s1, s2, dp);
//         int c1 = 1 + func(i, j-1, s1, s2, dp); // insert
//         int c2 = 1 + func(i-1, j, s1, s2, dp); // delete
//         int c3 = 1 + func(i-1, j-1, s1, s2, dp);// replace
//         return dp[i][j] = min({c1, c2, c3});
//     }
//     int minDistance(string word1, string word2) 
//     {
        // int l1 = word1.size();
        // int l2 = word2.size();
        // vector<vector<int>> dp(l1, vector<int>(l2, -1));
//         return func(l1-1, l2-1, word1, word2, dp);
//     }
// };