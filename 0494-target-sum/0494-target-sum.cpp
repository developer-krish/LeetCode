class Solution {
public:
    int subsetSum(vector<int>& nums, int target)
    {
        int n = nums.size();
        vector<vector<int>>t(n + 1, vector<int>(target + 1, 0));
        for(int i = 0 ; i <= n ; i++)
           t[i][0] = 1;
        for(int i = 1 ; i <= n ; i++)
        {
            for(int j = 1 ; j <= target ; j++)
            {
                if(nums[i - 1] <= j)
                   t[i][j] = t[i - 1][j] + t[i - 1][j - nums[i - 1]];
                else
                   t[i][j] = t[i - 1][j];
            }
        }
        return t[n][target];
    }
    int findTargetSumWays(vector<int>& nums, int target) 
    {
        int sum = 0;
        for(int i = 0 ; i < nums.size() ; i++)
           sum += nums[i];
        if ((sum + target) % 2 != 0 || sum < abs(target))
            return 0;
        int s1 = (sum + target) / 2;
        int countZeros = count(nums.begin(), nums.end(), 0);
        vector<int> filtered;
        for (int num : nums)
            if (num != 0)
                filtered.push_back(num);

        return subsetSum(filtered, s1) * (1 << countZeros);
    }
};