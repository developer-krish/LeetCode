class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) 
    {
        long long sum = 0;
        long long maxSum = 0;
        int i = 0, j = 0;
        int freq[10005] = {};
        int n = nums.size();
        while(j < n)
        {
            sum += nums[j];
            freq[nums[j]]++;
            while(freq[nums[j]] > 1 || j - i + 1 > k)
            {
                freq[nums[i]]--;
                sum -= nums[i];
                i++;
            }
            if(j - i + 1 == k)
               maxSum = max(maxSum, sum);
            j++;
        }
        return maxSum;
        
    }
};