class Solution {
public:
    int findMaxLength(vector<int>& nums) 
    {
        unordered_map<int, int> mpp;
        int n = nums.size();
        int count = 0;
        int maxLen = 0;
        mpp[0] = -1;
        for(int i = 0 ; i < n ; i++)
        {
            count += (nums[i] == 1) ? 1 : -1;
            if(mpp.find(count) != mpp.end())
               maxLen = max(maxLen, i - mpp[count]);
            else
               mpp[count] = i;
        }
        return maxLen;
    }
};