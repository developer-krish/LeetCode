class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) 
    {
        long long sum = 0;
        int i = 0, j = 0;
        long long maxi = 0;
        unordered_set<int> seen;
        while(j < nums.size())
        { 
            while(seen.find(nums[j]) != seen.end())
            {
                seen.erase(nums[i]);
                sum -= nums[i];
                i++;

            }
            seen.insert(nums[j]);
            sum += nums[j];
            if(j - i + 1 < k)
               j++;
            else if(j - i + 1 == k)
            {
                maxi = max(sum, maxi);
                seen.erase(nums[i]);
                sum -= nums[i];
                i++;
                j++;
            }
                          
        }
        return maxi;
        
    }
};