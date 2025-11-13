class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) 
    {
        vector<int> result;
        int n = nums.size();
        for(int i = 0 ; i < n ; i++)
        {
            int ind = abs(nums[i]) - 1;
            if(nums[ind] < 0) result.push_back(ind + 1);
            else nums[ind] = -nums[ind];
        }
        return result;
    }
};