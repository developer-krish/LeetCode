class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) 
    {
        int n = positions.size();

        vector<int> actualIndex(n);

        for(int i = 0 ; i < n ; i++)
        {
            actualIndex[i] = i;
        }

        sort(actualIndex.begin(), actualIndex.end(), [&](int i, int j){
            return positions[i] < positions[j];
        });

        vector<int> result;
        stack<int> st;

        for(auto& currIdx : actualIndex)
        {
            if(directions[currIdx] == 'R')
                st.push(currIdx);
            else
            {
                while(!st.empty() && healths[currIdx] > 0)
                {
                    int topIdx = st.top();
                    st.pop();

                    if(healths[topIdx] > healths[currIdx])
                    {
                        healths[topIdx]--;
                        healths[currIdx] = 0;
                        st.push(topIdx);
                    }
                    else if(healths[topIdx] < healths[currIdx])
                    {
                        healths[currIdx]--;
                        healths[topIdx] = 0;
                    }
                    else
                    {
                        healths[currIdx] = 0;
                        healths[topIdx] = 0;
                    }
                }
            }
        }

        for(int i = 0 ; i < n ; i++)
        {
            if(healths[i]) result.push_back(healths[i]);
        }

        return result;
        
    }
};