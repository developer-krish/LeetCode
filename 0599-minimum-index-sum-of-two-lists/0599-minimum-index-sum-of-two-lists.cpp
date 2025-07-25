class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) 
    {
        unordered_map<string, int> mpp;
        int minInd = INT_MAX;
        vector<string> ans;
        for(int i = 0 ; i < list1.size() ; i++)
        {
            mpp[list1[i]] = i; 
        }
        for(int i = 0 ; i < list2.size() ; i++)
        {
            if(mpp.find(list2[i]) == mpp.end()) continue;
            if(minInd > mpp[list2[i]] + i)
            {
                minInd = mpp[list2[i]] + i;
                ans.clear();
                ans.push_back(list2[i]);
            }
            else if(minInd == mpp[list2[i]] + i)
                ans.push_back(list2[i]);
        }
        return ans;
    }
};