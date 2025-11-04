class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) 
    {
        unordered_map<int, int> mpp;
        int i = 0 , j = 0;
        vector<int> ans;
        int n = nums.size();
        while(j < n)
        {
            mpp[nums[j]]++;
            if(j - i + 1 == k)
            {
                vector<pair<int, int>> temp;
                for(auto& it : mpp)
                   temp.push_back({it.first, it.second});// {number, frequency}

                sort(temp.begin(), temp.end(), [](auto& a, auto& b){
                    if(a.second == b.second)
                        return a.first > b.first;
                    return a.second > b.second;
                });
                int sum = 0;
                
                for(int cnt = 0 ; cnt < x && cnt < temp.size(); cnt++)
                    sum += temp[cnt].first * temp[cnt].second;
                
                ans.push_back(sum);
                if(--mpp[nums[i]] == 0)
                    mpp.erase(nums[i]);
                i++;
                j++;
            }
            else
               j++;
        }
        return ans;
    }
};