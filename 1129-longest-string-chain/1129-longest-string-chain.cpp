class Solution {
public:
    bool comparee(string& s1, string& s2)
    {
        if(s1.size() != s2.size() + 1) return false;
        int f = 0;
        int s = 0;
        while(f < s1.size())
        {
            if(s1[f] == s2[s])
            {
                f++;
                s++;
            }
            else // if(one added char arrives)
               f++;
        }
        if(f == s1.size() && s == s2.size()) return true;
        else return false;
    }
    static bool comp(const string& s1, const string&s2)
    {
        return s1.size() < s2.size();
    }
    int longestStrChain(vector<string>& words) 
    {
        sort(words.begin(), words.end(), comp); // in question we have to find sequenece(subset) not subsequence
        int n = words.size();
        vector<int> dp(n, 1);
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < i ; j++)
            {
                if(comparee(words[i], words[j]) && 1 + dp[j] > dp[i])
                {
                    dp[i] = 1 + dp[j];
                }

            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};