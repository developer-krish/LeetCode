class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long xorr = 0;
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            xorr ^= nums[i];
        }

        long long mask = xorr & -xorr; // (-xorr flips the bits and add 1 i.e 2s complement) -> provides the rightmost different bits in those two numbers as set and else bits as reset.

        int b1 = 0, b2 = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] & mask) // if it gives zero, means that bit position not matches, and may the our answer.
                b1 ^= nums[i]; // and we are comtinuously deleting the same ones through ^.
            else
                b2 ^= nums[i];
        }
        return {b1, b2};
    }
};
