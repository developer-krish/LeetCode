class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) 
    {
        int n = arr.size();
        vector<int> dp(n+1, 0);
        int sum = 0;
        for(int i = n - 1 ; i >= 0 ; i--)
        {
           int maxAns = INT_MIN;
           int maxi = INT_MIN;
           int length = 0;
           for(int j = i ; j < min(n, i + k) ; j++)
           {
              length++;
              maxi = max(maxi, arr[j]);
              sum = (length * maxi) + dp[j + 1];
              maxAns = max(maxAns, sum);
           }
           dp[i] = maxAns;
        }
        return dp[0];
    }
};

// memo
// class Solution {
// public:
//     int func(int ind, int k, vector<int>& arr, vector<int>& dp, int sum)
//     {
//         int n = arr.size();
//         if(ind == n) return 0;
//         int maxAns = INT_MIN;
//         int maxi = INT_MIN;
//         int length = 0;
//         if(dp[ind] != -1) return dp[ind];
//         for(int j = ind ; j < min(n, ind+k) ; j++)
//         {
//             length++;
//             maxi = max(maxi, arr[j]);
//             sum = (length * maxi) + func(j + 1, k, arr, dp, sum);
//             maxAns = max(maxAns, sum);
//         }
//         return dp[ind] = maxAns;
//     }
//     int maxSumAfterPartitioning(vector<int>& arr, int k) 
//     {
//         int n = arr.size();
//         vector<int> dp(n, -1);
//         int sum = func(0, k, arr, dp, 0);
//         return sum;
//     }
// };