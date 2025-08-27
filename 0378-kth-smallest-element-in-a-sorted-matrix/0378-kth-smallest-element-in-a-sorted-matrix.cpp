class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) 
    {
        priority_queue<int> pq;
        int n = matrix.size();
        for(int i = 0 ; i < n * n ; i++)
        {
            pq.push(matrix[i / n][i % n]);
            if(pq.size() > k) pq.pop();
        }
        return pq.top();
    }
};