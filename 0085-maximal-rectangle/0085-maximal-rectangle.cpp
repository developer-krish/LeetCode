class Solution {
public:
    int MAH(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> left(n), right(n);
        int maxArea = INT_MIN;
        stack<int> st;

        // Left smaller
        for(int i = 0; i < n; i++) {
            while(!st.empty() && nums[st.top()] >= nums[i])
                st.pop();
            left[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // Right smaller
        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && nums[st.top()] >= nums[i])
                st.pop();
            right[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        for (int i = 0; i < n; ++i) {
            int width = right[i] - left[i] - 1;
            int area = width * nums[i];
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) 
    {
        if (matrix.empty() || matrix[0].empty()) return 0;

        int n = matrix.size(), m = matrix[0].size();
        vector<int> v(m);
        
        // Initialize first row
        for(int j = 0; j < m; j++)
            v[j] = matrix[0][j] - '0';

        int mx = MAH(v);

        for(int i = 1; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(matrix[i][j] == '0')
                    v[j] = 0;
                else
                    v[j] += matrix[i][j] - '0';
            }
            mx = max(mx, MAH(v));
        }

        return mx;
    }
};
