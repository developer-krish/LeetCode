class Solution {
public:
    int getNumber(int n)
    {
        int output = 0;
        while(n > 0)
        {
            int digit = n % 10;
            output += digit * digit;
            n /= 10;
        }
        return output;
    }
    bool isHappy(int n) 
    {
        unordered_set<int> visit;
        while(visit.find(n) == visit.end())
        {
            visit.insert(n);
            n = getNumber(n);
            if(n == 1)  return true;
        }
        return false;
    }
};