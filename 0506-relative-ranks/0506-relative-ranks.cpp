class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) 
    {
        priority_queue<pair<int, int>> pq;
        int n = score.size();
        vector<string> ans(n);
        for(int i = 0 ; i < n ; i++)
        {
            pq.push({score[i], i});
        }
        int count = 1;
        while(!pq.empty())
        {
            int ind = pq.top().second;
            pq.pop();
            if(count == 1) ans[ind] = "Gold Medal";
            else if(count == 2) ans[ind] = "Silver Medal";
            else if(count == 3) ans[ind] = "Bronze Medal";
            else ans[ind] = to_string(count);
            count++;
        }
        return ans;
    }
};