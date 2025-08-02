class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n);
        vector<int> right(n);
        int maxArea = 0;
        stack<int> st;

        // find index of nearest smallest to left 
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && heights[st.top()] >= heights[i])
                st.pop();
            if (st.empty()) left[i] = -1;
            else left[i] = st.top();
            st.push(i);
        }

        // Clear the stack
        while (!st.empty()) st.pop();

        // find index of nearest smallest to right
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && heights[st.top()] >= heights[i])
                st.pop();
            if (st.empty()) right[i] = n;
            else right[i] = st.top();
            st.push(i);
        }

        // Calculate max area
        for (int i = 0; i < n; ++i) {
            int width = right[i] - left[i] - 1;
            int area = width * heights[i];
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
};
