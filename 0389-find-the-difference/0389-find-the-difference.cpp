class Solution {
public:
    char findTheDifference(string s, string t) 
    {
        unordered_map<char, int> mpp;
        int n = s.size();
        for(int i = 0 ; i < n ; i++)
        {
            mpp[s[i]]++;
        }
        int m = t.size();
        for(int i = 0 ; i < m ; i++)
        {
            if(mpp.find(t[i]) == mpp.end() || mpp[t[i]] == 0)
                return t[i];
            mpp[t[i]]--;
        }
        return ' ';
    }
};