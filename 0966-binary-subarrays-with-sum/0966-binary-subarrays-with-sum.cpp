class Solution {
public:
    int cal(vector<int>& nums, int goal)
    {
        // here we are counting no. of subarrays whose sum is less than goal
        if(goal < 0) return 0;
        int i = 0, j = 0;
        int n = nums.size();
        int sum = 0;
        int count = 0;
        while(j < n)
        {
            sum += nums[j];
            while(sum > goal)
            {
                sum -= nums[i];
                i++;
            }
            count += j - i + 1; // subarray counting
            j++;
        }
        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) 
    {
        return cal(nums, goal) - cal(nums, goal - 1);
    }
};