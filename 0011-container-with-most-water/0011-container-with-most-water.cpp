class Solution {
public:
    int maxArea(vector<int>& height) 
    {
        int right = height.size()-1;
        int maxi = INT_MIN;
        int left = 0;
        while(left < right)
        {
            int width = right - left;
            int h = min(height[left], height[right]);
            long long area = (long long) h * width;
            maxi = max(maxi, (int) area);
            if(height[left] < height[right])
               left++;
            else 
                right--;
        }
        return maxi;
    }
};