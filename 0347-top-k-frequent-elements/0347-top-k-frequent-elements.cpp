class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        int n = nums.size();
        unordered_map <int, int> freq;
        for(int num : nums)
        {
            freq[num]++;
        }
        vector<vector<int>> bucket(n + 1);
        for(auto& entry : freq)
        {
            int num = entry.first;
            int fq = entry.second;
            bucket[fq].push_back(num);
        }
        vector<int> result;
        for(int i = n ; i >= 0 && result.size() < k ; i--)
        {
            for(int num : bucket[i])
            {
                result.push_back(num);
                if(result.size() == k) break;
            }
        }
        return result;
    }
};