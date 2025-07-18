class Solution {
public:// longest subarray woith atmost k zeroes
    int longestOnes(vector<int>& nums, int k) 
    {
        int i = 0, j = 0;
        int n = nums.size();
        int cnt = 0;
        int maxLen = 0;
        while(j < n)
        {
            if(nums[j] == 0)
               cnt++;
            while(cnt > k)
            {
                if(nums[i] == 0)
                   cnt--;
                i++;  
            }
            maxLen = max(maxLen, j - i + 1);
            j++;
        }
        return maxLen;
    }
};