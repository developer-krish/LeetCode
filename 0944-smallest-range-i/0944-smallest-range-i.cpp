class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) 
    {
        int maxi = *max_element(nums.begin(), nums.end());
        int mini = *min_element(nums.begin(), nums.end());
        if(maxi - mini - 2 * k <= 0 || nums.size() == 1) return 0;
        return (maxi - mini - 2 * k);
    }
};