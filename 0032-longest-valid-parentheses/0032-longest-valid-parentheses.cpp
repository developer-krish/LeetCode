class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1); // base for valid substring index
        int maxLen = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') 
                st.push(i);  // store index of '('
            else 
            {
                st.pop();  // match with last '('
                if (!st.empty()) 
                    maxLen = max(maxLen, i - st.top());
                else 
                    st.push(i); // reset base index
            }
        }
        return maxLen;
    }
};
