class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) 
    {
        vector<int>freeTime;
        freeTime.push_back(startTime[0]);
        for(int i = 1 ; i < startTime.size() ; i++)
        {
            freeTime.push_back(startTime[i] - endTime[i - 1]);
        }
        freeTime.push_back(eventTime - endTime[endTime.size() - 1]);
        int i = 0, j = 0;
        int n = freeTime.size();
        int sum = 0;
        int maxSum = INT_MIN;
        while(j < n)
        {
            sum += freeTime[j];
            if(j - i + 1 < k + 1)
                j++;
            else if(j - i + 1 == k + 1)
            {
                maxSum = max(sum, maxSum);
                sum -= freeTime[i];
                i++;
                j++;
            }  
        }
        return maxSum;
    }
};