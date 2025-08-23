class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) 
    {
        int n = customers.size();
        int base = 0;
        for (int i = 0; i < n; i++) {
            if (grumpy[i] == 0) {
                base += customers[i];
            }
        }
        int i = 0 , j = 0;
        int extra = 0;
        int maxExtra = 0;
        while(j < n)
        {
            if(grumpy[j] == 1)
               extra += customers[j];
            if(j - i + 1 < minutes)
               j++;
            else if(j - i + 1 == minutes)
            {
                maxExtra = max(maxExtra, extra);
                if (grumpy[i] == 1) extra -= customers[i];
                i++;
                j++;
            }
        }
        return base + maxExtra;
    }
};