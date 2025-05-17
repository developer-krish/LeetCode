class Solution {
public:
    int numDecodings(string s) 
    {
        int n = s.size();
        vector<int> dp(n + 2, 0);
        dp[n] = 1;
        for(int i = n - 1 ; i >= 0 ; i--)
        {
            if(s[i] == '0')
            {
                dp[i] = 0;
                continue;
            } 
            int res = dp[i+1];
            if(i + 1 < n)
            {
                int twoDigit = (s[i] - '0') * 10 + (s[i + 1] - '0');
                if(twoDigit <= 26)
                   res += dp[i+2];
            }
            dp[i] = res;
        }
        return dp[0];
    }
};

// memo
// class Solution {
// public:
//     int func(int i, string &s, vector<int>& dp) {
//         int n = s.size();
//         if (i == n) return 1;      
//         if (s[i] == '0') return 0;     
//         if (dp[i] != -1) return dp[i];

//         int res = func(i + 1, s, dp);  

//         if (i + 1 < n) {
//             int twoDigit = (s[i] - '0') * 10 + (s[i + 1] - '0');
//             if (twoDigit <= 26)
//                 res += func(i + 2, s, dp); 
//         }

//         return dp[i] = res;
//     }

//     int numDecodings(string s) {
//         int n = s.size();
//         vector<int> dp(n + 1, -1);
//         return func(0, s, dp);
//     }
// };
