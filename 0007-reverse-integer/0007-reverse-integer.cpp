class Solution {
public:
    int reverse(int x) 
    {
        int val = 0;
        while(x != 0)
        {
            int rem = x % 10;
            if((val > INT_MAX / 10) || (val < INT_MIN / 10)) return 0;
            val = val * 10 + rem;
            x /= 10;
        }
        return val;
    }
};