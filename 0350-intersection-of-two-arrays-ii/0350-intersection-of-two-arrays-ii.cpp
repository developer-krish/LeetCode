class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) 
    {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int n = nums1.size();
        int m = nums2.size();
        int i = 0 , j = 0;
        vector<int> ans;
        while(i < n && j < m)
        {
            if(nums1[i] == nums2[j])
            {
                ans.push_back(nums1[i]);
                i++; j++;
            }
            else if(nums1[i] > nums2[j])
                j++;
            else 
                i++;
        }
        return ans;
    }
};