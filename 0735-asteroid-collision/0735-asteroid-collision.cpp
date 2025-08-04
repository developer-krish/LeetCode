class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        int n = asteroids.size();
        for (int i = 0; i < n; i++) 
        {
            bool destroyed = false;

            while (!st.empty() && asteroids[i] < 0 && st.top() > 0) 
            {
                if (abs(asteroids[i]) > abs(st.top()))
                    st.pop(); // Top asteroid destroyed, continue checking
                else if (abs(asteroids[i]) == abs(st.top())) 
                {
                    st.pop(); // Both destroyed
                    destroyed = true;
                    break;
                } 
                else 
                {
                    // Incoming asteroid is smaller
                    destroyed = true;
                    break;
                }
            }

            // Only push if not destroyed in collisions
            if (!destroyed) {
                st.push(asteroids[i]);
            }
        }

        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
