class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) 
    {
        int i = 0, j = 0;
        int n = nums.size();
        int sum = 0;
        double avg = 0;
        double maxAvg = INT_MIN;
        while(j < n)
        {
            sum += nums[j];
            if(j - i + 1 < k)
              j++;
            else if(j - i + 1 == k)
            {
                avg = (double) sum / k;
                maxAvg = max(maxAvg, avg);
                sum -= nums[i];
                i++;
                j++;
            }           
        }
        return maxAvg;
    }
};