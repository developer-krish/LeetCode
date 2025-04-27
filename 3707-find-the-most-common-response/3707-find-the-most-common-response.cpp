class Solution {
public:
 
    string findCommonResponse(vector<vector<string>>& responses) 
    {
        unordered_map<string, int> freq;
        for(auto res : responses)
        {
            unordered_set <string> unique(res.begin(), res.end());
            for(auto& respo : unique)
            {
                freq[respo]++;
            }
        }
    
       int maxFreq = 0;
       string result = "";
       for(auto&[response, count] : freq)
       {
           if(count >  maxFreq || (count == maxFreq && response < result))
           {
               maxFreq = count;
               result = response;
           }
       }
        return result;
    }
};