class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) 
    {
        vector<vector<int>> nums(n + 1, vector<int>(n , 0));
        for(auto& q : queries)
        {
            int r1 = q[0], c1 = q[1], r2 = q[2], c2 = q[3];
            nums[r1][c1]++;
            nums[r2 + 1][c1]--;
            if(c2 + 1 < n)
            {
                nums[r1][c2 + 1]--;
                nums[r2 + 1][c2 + 1]++;
            }
        }
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 1 ; j < n ; j++)
            {
                nums[i][j] += nums[i][j - 1];
            }
        }
        for(int j = 0 ; j < n ; j++)
        {
            for(int i = 1 ; i < n ; i++)
            {
                nums[i][j] += nums[i - 1][j];
            }
        }
        nums.resize(n);
        return nums;
    }
};