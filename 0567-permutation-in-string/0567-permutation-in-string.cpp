class Solution {
public:
    bool checkInclusion(string s1, string s2) 
    {
        int k = s1.size();
        int i = 0, j = 0;
        unordered_map<char, int> mpp;
        int n = s2.size();
        for(int i = 0 ; i < k ; i++)
        {
            mpp[s1[i]]++;
        }
        int count = mpp.size();
        while(j < n)
        {
            if(mpp.find(s2[j]) != mpp.end())
            {
                mpp[s2[j]]--;
                if(mpp[s2[j]] == 0)
                   count--;
            }
            if(j - i + 1 == k)
            {
                if(count == 0) return true;
                if(mpp.find(s2[i]) != mpp.end())
                {
                    if(mpp[s2[i]] == 0) count++;
                    mpp[s2[i]]++;
                }
                i++;    
            }
            j++;
        }
        return false;
    }
};