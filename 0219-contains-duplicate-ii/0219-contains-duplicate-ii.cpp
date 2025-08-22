class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) 
    {
        unordered_map<int, int> mpp;
        int n = nums.size();
        for(int i = 0 ; i < n ; i++)
        {
            int val = nums[i];
            if(mpp.find(val) != mpp.end() && i - mpp[val] <= k)
                return true;
            mpp[val] = i;
        }
        return false;
    }
};