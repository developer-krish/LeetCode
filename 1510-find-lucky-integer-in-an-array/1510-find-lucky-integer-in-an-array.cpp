class Solution {
public:
    int findLucky(vector<int>& arr) 
    {
        unordered_map <int, int> mpp;
        int maxi = -1;
        for(int num : arr)
        {
            mpp[num]++;
        }
        for(auto& it : mpp)
        {
            if(it.first == it.second)
               maxi = max(maxi, it.first);
        }
        return maxi;
        
    }
};