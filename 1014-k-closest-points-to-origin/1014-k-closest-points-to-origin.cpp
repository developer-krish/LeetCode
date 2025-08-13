class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) 
    {
        priority_queue<pair<long long, pair<int, int>>> pq; // max heap
        vector<vector<int>> result;

        for (auto &point : points)
        {
            int x = point[0];
            int y = point[1];
            long long dist = 1LL * x * x + 1LL * y * y; // squared distance
            pq.push({dist, {x, y}});
            if (pq.size() > k)
                pq.pop(); // remove farthest
        }

        while (!pq.empty())
        {
            result.push_back({pq.top().second.first, pq.top().second.second});
            pq.pop();
        }
        return result;
    }
};
