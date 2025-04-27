class Solution {
public:
    int func(int ind, vector<int>& nums, vector<int>& t)
    {
        if(ind == 0) return nums[0];
        if(ind < 0) return 0;
        if(t[ind] != -1) return t[ind];
        int take = nums[ind] + func(ind - 2, nums, t);
        int notTake = 0 + func(ind - 1, nums, t);
        return t[ind] = max(take, notTake);
    }
    int rob(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> t(n + 1, -1);
        return func(n - 1, nums, t);
    }
};