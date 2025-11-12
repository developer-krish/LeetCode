class Solution {
public:
    int findLHS(vector<int>& nums) 
    {
        unordered_map<int, int> mpp;
        int maxLen = INT_MIN;
        int n = nums.size();
        if(n == 1) return 0;
        for(int num : nums) mpp[num]++;
        if(mpp.size() == 1) return 0;
        for(auto& [x, f] : mpp)
        {
            if(mpp.count(x - 1))
               maxLen = max(maxLen, f + mpp[x - 1]);
        }
        return (maxLen == INT_MIN) ? 0 : maxLen;
    }
};