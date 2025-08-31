class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end());
        long long total = 0;
        while(k-- && !pq.empty())
        {
            int top = pq.top();
            pq.pop();
            total += top;
            pq.push((top + 2 )/3);
        }
        return total;
    }
};