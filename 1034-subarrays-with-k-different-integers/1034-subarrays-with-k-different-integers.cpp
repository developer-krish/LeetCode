class Solution {
public:
    int cal(vector<int>& nums, int k)
    {
         int i = 0, j = 0;
        unordered_map<int, int> mpp;
        int n = nums.size();
        int count = 0;
        while(j < n)
        {
           mpp[nums[j]]++;
           while(mpp.size() > k)
           {
               mpp[nums[i]]--;
               if(mpp[nums[i]] == 0) mpp.erase(nums[i]);
               i++;
           }
           count += j - i + 1;
           j++;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) 
    {
       return cal(nums, k) - cal(nums, k - 1);
    }
};