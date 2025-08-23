class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) 
    {
        sort(nums.begin(), nums.end());
        int i = 0, j = 0;
        int n = nums.size();
        long res = 0, total = 0;
        while(j < n)
        {
            total += nums[j];
            while(nums[j] * (long) (j - i + 1) > total + k)
            {
                total -= nums[i];
                i++;  
            }
            res = max(res, (long) j - i + 1);
            j++;
        }
        return (int) res;
        
    }
};