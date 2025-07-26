class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) 
    {
        int res = 0, n = points.size();
        for(int i = 0; i < n ; i++)
        {
            unordered_map<int, int> mpp;
            for(int j = 0 ; j < n ; j++)
            {
                if(i == j) continue;
                int dx = points[i][0] - points[j][0];
                int dy = points[i][1] - points[j][1];
                int distSq = dx * dx + dy * dy;
                mpp[distSq]++;
            }
            for(auto & [dist, count] : mpp)
              res += count * (count - 1);
        }
        return res;
    }
};