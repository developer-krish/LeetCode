class Solution {
public:
    int longestMountain(vector<int>& arr) 
    {
        int n = arr.size();
        int longest = 0;
        for(int i = 1 ; i < n - 1 ; i++)
        {
            if(arr[i - 1] < arr[i] && arr[i + 1] < arr[i]) // find peak
            {
                int left = i, right = i;
                while(left > 0 && arr[left - 1] < arr[left]) left--;
                while(right < n - 1 && arr[right + 1] < arr[right]) right++;
                longest = max(longest, right - left + 1);
            }
        }
        return longest;
    }
};