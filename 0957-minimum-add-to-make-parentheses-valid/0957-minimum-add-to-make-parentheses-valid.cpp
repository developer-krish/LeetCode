class Solution {
public:
    int minAddToMakeValid(string s) 
    {
        stack<int> st;
        int n = s.size();
        for(int i = 0 ; i < n ; i++)
        {
            if(!st.empty() && s[i] == ')' && st.top() == '(')
               st.pop();
            else
               st.push(s[i]);
        }
        return st.size();
    }
};