class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) 
    {
        int n = nums.size();
       priority_queue<int, vector<int>, greater<int>> pq;
       unordered_map<int, int> mpp;
       for(int i = 0 ; i < n ; i++)
       {
           mpp[nums[i]]++;
       }
       for(auto h : mpp)
       {
          pq.push(h.first);
       }
       while(!pq.empty())
       {
           int val = pq.top();
           for(int i = val ; i < val + k ; i++)
           {
               if(mpp[i] == 0) return false;
               else mpp[i]--;
               while(!pq.empty() && mpp[pq.top()] == 0)
               {
                   pq.pop();
               }
           }
       }
       return true;
    }
};