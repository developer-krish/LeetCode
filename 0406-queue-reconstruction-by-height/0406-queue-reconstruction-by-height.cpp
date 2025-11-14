class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) 
    {
        sort(people.begin(), people.end(), [](auto& a, auto& b)
        {
            return a[0] == b[0] ? a[1] < b[1] : a[0] > b[0]; 
            // decending order, if p[0] is same then p[1] with larger value is taken first
        });
        vector<vector<int>> ans;
        for(auto& p : people)
        {
            ans.insert(ans.begin() + p[1], p); 
            // When you insert something inside a vector (not at the end), all existing elements shift to the right automatically
        }
        return ans;
    }
};