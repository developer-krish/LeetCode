class Solution {
public:
    string removeKdigits(string num, int k) 
    {
        stack<int> st;
        int n = num.size();
        for(int i = 0 ; i < n ; i++)
        {
            while(!st.empty() && k > 0 && (st.top() - '0') > num[i] - '0')
            {
                st.pop();
                k--;
            }
            st.push(num[i]);
        }

        // if k still not equal to 0 i.e num is like "123456"
        while(k > 0)
        {
            st.pop();
            k--;
        }

        if(st.empty()) return "0";
        string result = "";
        while(!st.empty())
        {
            result += st.top();
            st.pop();
        }

        reverse(result.begin(), result.end());

        // Remove leading zeros
        int i = 0;
        while (i < result.size() && result[i] == '0') i++;
        result = result.substr(i);

        return result.empty() ? "0" : result;
    }
};