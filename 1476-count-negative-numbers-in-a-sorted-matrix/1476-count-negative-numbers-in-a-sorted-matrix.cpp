class Solution {
public:
    int count(vector<int>& nums)
    {
        int low = 0, high = nums.size() - 1;
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            if(nums[mid] < 0)
               high = mid - 1;
            else 
               low = mid + 1;
        }
        return nums.size() - low;
    }
    int countNegatives(vector<vector<int>>& grid) 
    {
        int cnt = 0;
        for(auto& g : grid)
        {
            cnt += count(g);
        }
        return cnt;
    }
};