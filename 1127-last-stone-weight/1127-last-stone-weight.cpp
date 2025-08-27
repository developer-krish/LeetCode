class Solution {
public:
    int lastStoneWeight(vector<int>& stones) 
    {
        int n = stones.size();
        priority_queue<int> pq(stones.begin(), stones.end());
        while(pq.size() > 1)
        {
            int s1 = pq.top(); pq.pop();
            int s2 = pq.top(); pq.pop();
            int smash = s1 - s2;
            if(smash) pq.push(smash);
        }
        return pq.empty() ? 0 : pq.top();
    }
};