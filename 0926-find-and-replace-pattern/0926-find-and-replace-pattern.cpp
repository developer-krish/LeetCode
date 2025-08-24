class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) 
    {
        unordered_map <char, char> mpp;
        unordered_map <char, char> pmm;
        vector<string> ans;
        for(string word : words)
        {
            bool check = true;
            if(word.size() != pattern.size())
            {
                check = false;
                break;
            }
            for(int i = 0 ; i < word.size() ; i++)
            {
                if(mpp.find(pattern[i]) != mpp.end() && mpp[pattern[i]] != word[i] || pmm.find(word[i]) != pmm.end() && pmm[word[i]] != pattern[i])
                {
                    check = false;
                    break;
                }
                mpp[pattern[i]] = word[i];
                pmm[word[i]] = pattern[i];
            }
            if(check)
               ans.push_back(word);
            mpp.clear();
            pmm.clear();
        }
        return ans;
    }
};