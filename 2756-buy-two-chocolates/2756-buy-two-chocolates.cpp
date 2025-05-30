class Solution {
public:
    int buyChoco(vector<int>& prices, int money) 
    {
        int n = prices.size();
        int firstMin = min(prices[0], prices[1]);
        int secondMin = max(prices[0], prices[1]);
        for(int i = 2 ; i < n ; i++)
        {
            if(prices[i] < firstMin)
            {
                secondMin = firstMin;
                firstMin = prices[i];
            }
            else if(prices[i] < secondMin)
                secondMin = prices[i];
        }
        int cost = firstMin + secondMin;
        if(cost <= money)
           return money - cost;
        return money;
    }
};

// class Solution {
// public:
//     int buyChoco(vector<int>& prices, int money) 
//     {
//         sort(prices.begin(), prices.end());
//         int cost = prices[0] + prices[1];
//         if(cost <= money)
//            return money - cost;
//         return money;
//     }
// };