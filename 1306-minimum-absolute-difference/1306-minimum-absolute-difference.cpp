class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) 
    {
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        int minDiff = 2e6;
        int n = arr.size();
        for(int i = 0 ; i < n - 1 ; i++)
        {
            int diff = arr[i+1] - arr[i];
            if(diff < minDiff)
            {
                minDiff = diff;
                ans.clear();
                ans.push_back({arr[i], arr[i+1]});
            }
            else if(diff == minDiff)
                ans.push_back({arr[i], arr[i+1]});
        }
        return ans;
        
    }
};