class Solution {
public:
    int cal(vector<int>& nums, int k)
    {
        int i = 0, j = 0;
        int n = nums.size();
        int count = 0;
        int sum = 0;
        while(j < n)
        {
            // represnting odd num in terms of 1 and even om terms of 0
            // now it become similar to problem 930(Binary Subarray Sum)
            sum += (nums[j] % 2); 
            while(sum > k)
            {
                sum -= (nums[i] % 2);
                i++;
            }
            count += j - i + 1;
            j++;
        }
        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) 
    {
        return cal(nums, k) - cal(nums, k - 1); 
    }
};