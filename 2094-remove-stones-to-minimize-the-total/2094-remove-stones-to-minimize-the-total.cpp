class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) 
    {
        priority_queue<int> pq;
        int sum = 0;
        for(int num : piles) pq.push(num);
        while(k--)
        {
            int num = pq.top();
            pq.pop();
            num = num - floor(num / 2);
            pq.push(num);
        }
        while(!pq.empty())
        {
            sum += pq.top();
            pq.pop();
        }
        return sum;
    }
};