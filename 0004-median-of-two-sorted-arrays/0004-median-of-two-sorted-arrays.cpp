class Solution {
public:
    vector <int> merge(vector<int>& nums1, vector<int>& nums2)
    {
        int i = 0, j = 0;
        int n2 = nums2.size();
        int n1 = nums1.size();
        vector <int> mergeArr;
        while(i < n1 && j < n2)
        {
            if(nums1[i] < nums2[j])
                mergeArr.push_back(nums1[i++]);
            else 
                mergeArr.push_back(nums2[j++]);
        }
        while(i < n1)
           mergeArr.push_back(nums1[i++]);
        while(j < n2)
           mergeArr.push_back(nums2[j++]);
        return mergeArr;
    }
    double median(vector<int>& nums)
    {
        int low = 0;
        int high = nums.size();
        int mid = (low + high) / 2;
        if(nums.size() % 2 == 0)
        {
            mid--;
            return  (double) (nums[mid] + nums[mid + 1]) / 2;
        }
        return (double) nums[mid];
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<int> mergeArr;
        mergeArr = merge(nums1, nums2);
        return median(mergeArr);
    }
};