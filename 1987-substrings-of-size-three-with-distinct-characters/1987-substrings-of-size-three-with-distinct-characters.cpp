class Solution {
public:
    int countGoodSubstrings(string s) 
    {
        int i = 0, j = 0;
        int n = s.size();
        int count = 0;
        unordered_map<char, int> mpp;
        while(j < n)
        {
           mpp[s[j]]++;
           while(mpp.size() < j - i + 1) // contains duplicate
           {
               mpp[s[i]]--;
               if(mpp[s[i]] == 0)
                   mpp.erase(s[i]);
               i++;
           }
           if(mpp.size() == 3)
           {
               count++;
               if(mpp.find(s[i]) != mpp.end())
               {
                  mpp[s[i]]--;
                  if(mpp[s[i]] == 0)
                    mpp.erase(s[i]);
               }
                i++;
           }
           j++;
        }
        return count;
    }
};