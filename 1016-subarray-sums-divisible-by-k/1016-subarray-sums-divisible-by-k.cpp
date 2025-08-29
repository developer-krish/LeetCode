class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) 
    {
        unordered_map<int, int> mpp;
        int n = nums.size();
        int sum = 0;
        int count = 0;
        mpp[0] = 1;
        for(int i = 0 ; i < n ; i++)
        {
            sum += nums[i];
            int rem = sum % k;
            if(rem < 0) rem += k;
            if(mpp.find(rem) != mpp.end())
            {
                count += mpp[rem];
            }
            mpp[rem]++;
        }
        return count;
    }
};