class Solution {
public:
    bool isIsomorphic(string s, string t) 
    {
        if (s.size() != t.size()) return false;
        unordered_map<char, char>st;
        unordered_map<char, char>ts;
        for(int i = 0 ; i < s.size() ; i++)
        {
            char sc = s[i], tc = t[i];
            if(st.count(sc) && st[sc] != tc) return false;
            if(ts.count(tc) && ts[tc] != sc) return false;
            st[sc] = tc;
            ts[tc] = sc;
        }
        return true;
    }
};