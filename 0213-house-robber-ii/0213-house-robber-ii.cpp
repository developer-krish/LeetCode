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
        if (n == 1)
           return nums[0];
        vector<int> temp1, temp2;
        for(int i = 0 ; i < n ; i++)
        {
            if(i != 0) temp1.push_back(nums[i]);
            if(i != n -1) temp2.push_back(nums[i]);
        }
        vector<int> t1(temp1.size(), -1);
        vector<int> t2(temp2.size(), -1);
        return max(func(temp1.size() - 1, temp1, t1), func(temp2.size() - 1, temp2, t2));
    }
};