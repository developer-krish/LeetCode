class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) 
    {
        int n = nums.size();
        int ans = 0;
        for(int i = 0 ; i < n ; i++)
        {
            if(nums[i] % 2 != 0 || nums[i] > threshold) continue;
            int length = 1;
            int lastParity = nums[i] % 2;;
            for(int j = i + 1 ; j < n ; j++)
            {
                if(nums[j] > threshold) break;
                if((nums[j] % 2) == lastParity) break;
                lastParity = nums[j] % 2;
                length++;
            }
            ans = max(ans, length);
        }
        return ans;
    }
};