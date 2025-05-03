class Solution {
public:
    bool isMatch(string s, string p) 
    {
        int l1 = s.size();
        int l2 = p.size();
        vector<vector<bool>> dp(l1+1, vector<bool>(l2+1, false));
        dp[0][0] = true;
        for(int i = 1 ; i <= l1 ; i++) dp[i][0] = false;
        for(int j = 1 ; j <= l2 ; j++)
        {
            bool flag = true;
            for(int c = 1 ; c <= j ; c++)
            {
                if(p[c  - 1] != '*')
                {
                    flag  =  false;
                }
            }
            dp[0][j] = flag;
        }
        for(int i = 1 ; i <= l1 ; i++)
        {
            for(int j = 1 ; j <= l2 ; j++)
            {
                if(s[i - 1] == p[j - 1] || p[j - 1] == '?')
                  dp[i][j] = dp[i-1][j-1];
                else if(p[j - 1] == '*')
                  dp[i][j] = dp[i-1][j] || dp[i][j-1];
                else 
                  dp[i][j] = false;
            }
        }
        return dp[l1][l2];
    }
};

// memo(MLE)
// class Solution {
// public:
//     bool func(int i, int j, string s1, string s2, vector<vector<int>>& dp)
//     {
//         if(i < 0 && j < 0) return true; // if both ends | (i == 0 && j == 0) -> +1 indexing
//         if(i >= 0 && j < 0) return false;// nothing in s2 for comparing | (i > 0 && j == 0)
//         if(i < 0 && j >= 0) //  (i == 0 && j > 0)
//         {
//             for(int c = 0 ; c <= j ; c++) // c = 1
//             {
//                 if(s2[c] != '*') // s2[c-1]
//                    return false;
//             }
//             return true;
//         }
//         if(dp[i][j] != -1) return dp[i][j];
//         if(s1[i] == s2[j] || s2[j] == '?') // (s1[i-1] == s2[j-1] || s2[j-1] == '?)
//            return dp[i][j] = func(i - 1, j - 1, s1, s2, dp);
//         if(s2[j] == '*') // s2[j-1]
//            return dp[i][j] = func(i - 1, j, s1, s2, dp) || func(i, j - 1, s1, s2, dp);
//         return false;
//     }
//     bool isMatch(string s, string p) 
//     {
//         int l1 = s.size();
//         int l2 = p.size();
//         vector<vector<int>> dp(l1, vector<int>(l2, -1)); // l1+1, l2+1(for +1 indexing)
//         return func(l1 - 1, l2 - 1, s, p, dp);  // l1, l2
//     }
// };