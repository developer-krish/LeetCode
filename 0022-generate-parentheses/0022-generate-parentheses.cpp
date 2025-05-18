class Solution {
public:
    void func(vector<string>& ans, string s, int n, int l, int r)
    {
        if(l == n && r == n)
        {
            ans.push_back(s);
            return;
        }
        if(l < n)
            func(ans, s + '(', n, l + 1, r);
        if(l > r && r < n)
            func(ans, s + ')', n, l, r + 1);
    }
    vector<string> generateParenthesis(int n) 
    {
        vector<string> ans;
        string s = "(";
        func(ans, s, n, 1, 0); // We start with 1 '(' already placed
        return ans;        
    }
};