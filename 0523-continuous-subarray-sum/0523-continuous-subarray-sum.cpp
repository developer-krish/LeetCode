class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) 
    {
        // If two prefix sums have the same remainder when divided by k, then the subarray between them has a sum divisible by k.
        unordered_map<int, int> mpp;
        mpp[0] = -1;
        int sum = 0;
        for(int i = 0; i < nums.size() ; i++)
        {
            sum += nums[i];
            int rem = sum % k;
            if(mpp.find(rem) != mpp.end())
            {
                if(i - mpp[rem] > 1)
                   return true;
            }
            else
               mpp[rem] = i;
        }
        return false;
    }
};