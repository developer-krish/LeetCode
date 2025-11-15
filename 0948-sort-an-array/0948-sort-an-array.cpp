class Solution {
public:
    void merge(vector<int>& nums, int lb, int mid, int ub)
    {
        int i = lb, j = mid + 1, k = 0;
        vector<int> temp(ub - lb + 1);
        while(i <= mid && j <= ub)
        {
            if(nums[i] < nums[j]) temp[k++] = nums[i++];
            else temp[k++] = nums[j++];
        }
        while(i <= mid) temp[k++] = nums[i++];
        while(j <= ub) temp[k++] = nums[j++];
        for(int x = 0 ; x < temp.size() ; x++)
        {
            nums[lb + x] = temp[x];
        }
    }
    void mergeSort(vector<int>& nums, int lb, int ub)
    {
        if(lb < ub)
        {
            int mid = (lb + ub) / 2;
            mergeSort(nums, lb, mid);
            mergeSort(nums, mid + 1, ub);
            merge(nums, lb, mid, ub);
        }
    }
    vector<int> sortArray(vector<int>& nums) 
    {
        int n = nums.size();
        mergeSort(nums, 0, n - 1);
        return nums;
    }
};