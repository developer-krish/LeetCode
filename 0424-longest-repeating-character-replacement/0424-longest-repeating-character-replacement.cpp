class Solution {
public:
    int characterReplacement(string s, int k) 
    {
        int l = 0;
        int r = 0;
        int maxLength = 0;
        int maxFreq = 0;
        vector<int> freq(26, 0);
        while(r < s.size())
        {
            freq[s[r] - 'A']++;
            maxFreq = max(maxFreq, freq[s[r] - 'A']);
            if((r - l + 1) - maxFreq > k)
            {
                freq[s[l] - 'A']--;
                maxFreq = 0;
                for(int i = 0 ; i < 25 ; i++) 
                   maxFreq = max(maxFreq, freq[i]);
                l++;
            }
            if((r - l + 1) - maxFreq <= k)
                maxLength = max(maxLength, r - l + 1);
            r++;
        }
        return maxLength;   
    }
};