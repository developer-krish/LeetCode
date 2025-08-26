class Solution {
public:
    double helper(vector<vector<int>>& dimensions, int ind)
    {
        int num1 = dimensions[ind][0] * dimensions[ind][0];
        int num2 = dimensions[ind][1] * dimensions[ind][1];
        return sqrt(1LL * num1 + 1LL * num2);
    }
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) 
    {
        int n = dimensions.size();
        double maxi = 0.0;
        int ind;
        for(int i = 0 ; i < n ; i++)
        {
            double dl = helper(dimensions, i);
            if(maxi < dl)
            {
                maxi = dl;
                ind = i;
            }
            else if(fabs(dl - maxi) < 1e-9)  // if diagonal length is same but just point lil bit differ
            { 
                int area1 = dimensions[i][0] * dimensions[i][1];
                int area2 = dimensions[ind][0] * dimensions[ind][1];
                if(area1 > area2) ind = i;    // pick larger area
            }
        }
        return dimensions[ind][0] * dimensions[ind][1];
    }
};
// fabs(x) = absolute value of a floating number (from <cmath>).
// 1e-9 = scientific notation, meaning 0.000000001 (very small).
// So this condition says:
// ➡️ “If the difference between d and maxi is smaller than 0.000000001, treat them as equal.”