class Solution {
public:
    void solve(vector<int>& nums, int ind, vector<int>& ans, set<vector<int>>& output)
    {
        if(ind >= nums.size())
        {
            if(ans.size() > 1)
               output.insert(ans);
            return;
        }
        if(ans.size() == 0 || nums[ind] >= ans.back())
        {
            ans.push_back(nums[ind]);
            solve(nums, ind + 1, ans, output);
            ans.pop_back();
        }
        solve(nums, ind + 1, ans, output);
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) 
    {
        vector<int> ans;
        set<vector<int>> output; // to avoid duplicate combinations
        solve(nums, 0, ans, output);
        return vector(output.begin(), output.end());
    }
};