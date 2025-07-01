class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        if(s.length() != t.length()) return false;
        unordered_map<char, int> mpp;
        for(char c : s)
        {
            mpp[c]++;
        }
        for(char c : t)
        {
            if(mpp.find(c) == mpp.end() || mpp[c] == 0)
               return false;
            mpp[c]--;


        }
        return true;
    }
};