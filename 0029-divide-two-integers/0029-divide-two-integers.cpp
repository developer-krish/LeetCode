class Solution {
public:
    int divide(int dividend, int divisor) 
    {
        if(dividend == divisor) return 1;

        bool sign = (dividend >= 0) == (divisor >= 0); // same sign → positive

        long n = labs(dividend);
        long d = labs(divisor);
        long ans = 0;

        while(n >= d)
        {
            long count = 0;
            while(n >= (d << (count + 1)))
            {
                count++;
            }
            ans += (1LL << count);
            n -= (d << count);
        }

        if(ans > INT_MAX) 
            return sign ? INT_MAX : INT_MIN;

        return sign ? (int)ans : -(int)ans;
    }
};
