class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) 
    {
        int l1 = str1.size();
        int l2 = str2.size();
        vector<vector<int>> dp(l1+1, vector<int>(l2+1, 0));
        for(int i = 0 ; i <= l1 ; i++)
           dp[i][0] = 0;
        for(int j = 0 ; j <= l2 ; j++)
           dp[0][j] = 0;
        
        for(int ind1 = 1 ; ind1 <= l1 ; ind1++)
        {
            for(int ind2 = 1 ; ind2 <= l2 ; ind2++)
            {
                if(str1[ind1 - 1] == str2[ind2 - 1])
                    dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
                else
                    dp[ind1][ind2] = max(dp[ind1 - 1][ind2], dp[ind1] [ind2 - 1]);
            }
        }
        int i = l1, j = l2;
        string ans = "";
        while(i > 0 && j > 0)
        {
            if(str1[i - 1] == str2[j - 1])
            {
                ans += str1[i - 1];
                i--;
                j--;
            }
            else if(dp[i-1][j] > dp[i][j-1])
            {
                ans += str1[i-1];
                i--;
            }
            else 
            {
                ans += str2[j-1];
                j--;
            }
        }
        while(i > 0) 
        {
            ans += str1[i-1];
            i--;
        }
        while(j > 0)
        {
            ans += str2[j-1];
            j--;
        }                  
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
};