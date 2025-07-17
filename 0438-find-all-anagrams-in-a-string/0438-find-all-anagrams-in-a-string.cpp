class Solution {
public:
    vector<int> findAnagrams(string s, string p) 
    {
        unordered_map<char, int> mpp;
        for(char c : p)
        {
            mpp[c]++;
        }
        int i = 0, j = 0;
        int n = s.size();
        int count = mpp.size();
        int k = p.size();
        vector<int> ans;
        while(j < n)
        {
            if(mpp.find(s[j]) != mpp.end())
            {
                mpp[s[j]]--;
                if(mpp[s[j]] == 0) count--;
            }
                
            if(j - i + 1 < k) 
               j++;
            else if(j - i + 1 == k)
            {
                if(count == 0)
                   ans.push_back(i);
                if(mpp.count(s[i]))
                {
                    if (mpp[s[i]] == 0) {
                        count++;
                    }
                    mpp[s[i]]++;
                }
                i++;
                j++;
            }   
        }
        return ans;
    }
};