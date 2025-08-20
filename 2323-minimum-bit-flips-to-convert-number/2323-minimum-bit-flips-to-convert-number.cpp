class Solution {
public:
    int minBitFlips(int start, int goal) 
    {
        int xorr = start ^ goal; // this have the set bits (which is equal to bit flips)
        int count = 0;
        // count number of set bits
        while(xorr > 0)
        {
            xorr = (xorr & xorr - 1);
            count++;
        }
        return count;
    }
};