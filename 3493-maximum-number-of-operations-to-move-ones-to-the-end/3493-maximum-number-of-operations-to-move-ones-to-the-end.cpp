class Solution {
public:
    int maxOperations(string s) 
    {
        int ones = 0;
        int n = s.size();
        int total = 0;
        for(int i = 0 ; i < n ; i++)
        {
            if(s[i] == '1') ones++;
            else if((i > 0) && s[i - 1] == '1') total += ones;
        }
        return total;
    }
};