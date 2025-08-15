class Solution {
public:
    int consecutiveNumbersSum(int n) 
    {
        int count = 0;
        for(long long m = 1 ; m * (m - 1)/2 < n ; m++)
        {
            if((n -  m * (m - 1) / 2) % m == 0)
               count++;
        }
        return count;
    }
};