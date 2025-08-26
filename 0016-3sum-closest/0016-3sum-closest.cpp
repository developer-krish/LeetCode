class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int result = nums[0] + nums[1] + nums[2];
        for(int i = 0 ; i < n - 2 ; i++)
        {
            int left = i + 1, right = n - 1;
            while(left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];
                if(abs(target - sum) < abs(target - result))
                   result = sum;
                if(sum > target) right--;
                else if(sum < target) left++;
                else return target;
            }
        }
        return result;
    }
};