class Solution {
public:
    int lenLongestFibSubseq(vector<int>& nums) 
    {
        int n = nums.size();
        int maxLen = INT_MIN;
        unordered_set<int> st(nums.begin(), nums.end());
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = i + 1 ; j < n ; j++)
            {
                int len = 2;
                int prev = nums[j];
                int curr = nums[i] + nums[j];
                while(st.find(curr) != st.end())
                {
                   int temp = curr;
                   curr += prev;
                   prev = temp;
                   maxLen = max(maxLen, ++len);
                }
            }
        }
        return (maxLen == INT_MIN) ? 0 : maxLen;
    }
};