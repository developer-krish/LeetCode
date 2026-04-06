class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<string> st;

        
        for (auto &obs : obstacles) 
        {
            string key = to_string(obs[0]) + "_" + to_string(obs[1]);
            st.insert(key);
        }

        int x = 0, y = 0;
        int maxD = 0;


        vector<pair<int,int>> dirs = {{0,1},{1,0},{0,-1},{-1,0}};
        int d = 0; 

        for (int cmd : commands) {
            if (cmd == -2) {
                
                d = (d + 3) % 4;
            } 
            else if (cmd == -1) {
                
                d = (d + 1) % 4;
            } 
            else {

                for (int step = 0; step < cmd; step++) {
                    int newX = x + dirs[d].first;
                    int newY = y + dirs[d].second;

                    string nextKey = to_string(newX) + "_" + to_string(newY);

                    
                    if (st.find(nextKey) != st.end()) {
                        break;
                    }

                    x = newX;
                    y = newY;

                    maxD = max(maxD, x*x + y*y);
                }
            }
        }

        return maxD;
    }
};