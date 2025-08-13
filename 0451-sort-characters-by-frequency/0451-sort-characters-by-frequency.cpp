class Solution {
public:
    string frequencySort(string s) 
    {
        priority_queue<pair<int, char>> pq; 
        unordered_map<char, int> mpp;
        int n = s.size();
        string result;
        result.reserve(n); // prevent repeated reallocations

        for (char c : s) 
            mpp[c]++;

        for (auto &it : mpp) 
            pq.push({it.second, it.first});

        while (!pq.empty()) 
        {
            auto top = pq.top(); 
            pq.pop();
            result += string(top.first, top.second); 
        }

        return result;
    }
};
