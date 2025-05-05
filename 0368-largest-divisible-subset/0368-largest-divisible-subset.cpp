class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) 
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> dp(n, 1);
        vector<int> hash(n, 1);
        int maxi = 1;
        int lastInd = 0;
        for(int ind = 0 ; ind < n ; ind++)
        {
            hash[ind] = ind;
            for(int prev = 0 ; prev < ind ; prev++)
            {
                if(nums[ind] % nums[prev] == 0 && 1 + dp[prev] > dp[ind])
                {
                    dp[ind] = 1 + dp[prev];
                    hash[ind] = prev;
                }
            }
            if(dp[ind] > maxi)
            {
               maxi = dp[ind];
               lastInd = ind;
            }
        }
        vector<int> temp;
        temp.push_back(nums[lastInd]);
        while(lastInd != hash[lastInd])
        {
            lastInd = hash[lastInd];
            temp.push_back(nums[lastInd]);
        }
        return temp;
    }
};