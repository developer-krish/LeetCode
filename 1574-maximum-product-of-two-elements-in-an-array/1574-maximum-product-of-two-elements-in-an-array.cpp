class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        priority_queue<int>pq;
        int n = nums.size();
        for(int num : nums)
        {
            pq.push(num);
        }
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();
        return (first - 1) * (second - 1);
    }
};