class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) 
    {
        int n = nums.size();
        int i = 0, j = 0;
        unordered_map<int, int> mpp;
        unordered_set<int> st(nums.begin(), nums.end());
        int k = st.size();
        int ans = 0;
        while(j < n)
        {
            mpp[nums[j]]++;
            while(mpp.size() == k)
            {
                ans += (n - j);
                mpp[nums[i]]--;
                if(mpp[nums[i]] == 0) mpp.erase(nums[i]);
                i++;
            }
            j++;
        }
        return ans;
    }
};