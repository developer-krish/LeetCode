class Solution {
public:
    int numOfSubarrays(vector<int>& arr) 
    {
        int n = arr.size();
        int MOD = 1000000007;
        int sum = 0;
        int result = 0;
        int odd = 0, even = 1;
        for(int i = 0 ; i < n ; i++)
        {
            sum += arr[i];
            if(sum % 2 == 1) //When prefix is odd, count how many even prefixes— because odd − even = odd.
            {
                result = (result + even) % MOD;
                odd++;
            }
            else
            {
                result = (result + odd) % MOD;
                even++;
            }  
        }
        return result;
    }
};