class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) 
    {
        unordered_map<char, int> mpp;
        for(char c : magazine)
        {
            mpp[c]++;
        }
       for (char c : ransomNote) 
       {
            if (mpp.find(c) == mpp.end() || mpp[c] == 0)
                return false;
            mpp[c]--;
        }
        return true;
    }
};