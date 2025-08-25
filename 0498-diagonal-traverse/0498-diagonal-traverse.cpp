class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) 
    {
        if(matrix.empty() || matrix[0].empty()) return {};
        int m = matrix.size(), n = matrix[0].size();
        vector<int> result(n * m);
        int row = 0, col = 0;
        for(int i = 0 ; i < m * n ; i++)
        {
            result[i] = matrix[row][col];
            if((row + col) % 2 == 0)
            {
                if(col == n - 1) row++;
                else if(row == 0) col++;
                else{col++; row--;}
            }
            else
            {
                if(row == m - 1) col++;
                else if(col == 0) row++;
                else{row++; col--;}
            }
        }
        return result;
    }
};

// Even sum → move up-right (row--, col++).
// Odd sum → move down-left (row++, col--).
// Boundary Conditions:

// While moving up-right:

// If we are at the last column, move down (row++).
// Else if we are at the first row, move right (col++).
// While moving down-left:

// If we are at the last row, move right (col++).
// Else if we are at the first column, move down (row++).
