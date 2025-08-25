class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) 
    {
        unordered_map<string, int> mpp;
        string word;

        stringstream ss1(s1);
        while(ss1 >> word)
        {
            mpp[word]++;
        }
        stringstream ss2(s2);
        while(ss2 >> word)
        {
            mpp[word]++;
        }
        vector<string> result;
        for(auto& p : mpp)
        {
            if(p.second == 1)
               result.push_back(p.first);
        }
        return result;
    }
};