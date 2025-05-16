class Solution {
public:
    void LPS(string &pattern, vector<int>& lps)
    {
        int length = 0;
        lps[0] = 0;
        int i = 1;
        while(i < pattern.size())
        {
            if(pattern[i] == pattern[length])
            {
                length++;
                lps[i] = length;
                i++;
            }
            else
            {
                if(length != 0)
                   length = lps[length - 1];
                else
                {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }
    int strStr(string haystack, string needle) 
    {
        int n = haystack.size();
        int m = needle.size();
        vector<int> lms(m);
        LPS(needle, lms);
        int i = 0;
        int j = 0;
        while(i < n)
        {
            if(needle[j] == haystack[i])
            {
                i++;
                j++;
            }
            if(j == m)
               return i - j;
            else if(i < n && needle[j] != haystack[i])
            {
                if(j != 0)
                   j = lms[j - 1];
                else
                   i++;
            }
        }
        return -1;
    }
};