class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) 
    {
        priority_queue<pair<int, int>> pq;
        int n = arr.size();
        vector<int> result;
        for(int i = 0 ; i < n ; i++)
        {
            pq.push({abs(arr[i] - x), arr[i]});
            if(pq.size() > k)
               pq.pop();
        }
        while(!pq.empty())
        {
            result.push_back(pq.top().second);
            pq.pop();
        }
        sort(result.begin(), result.end());
        return result;
    }
};