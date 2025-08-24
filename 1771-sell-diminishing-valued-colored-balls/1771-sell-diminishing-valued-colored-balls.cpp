#define mod 1000000007
class Solution {
public:
    int maxProfit(vector<int>& inventory, int orders) {
        sort(inventory.begin(), inventory.end());
        long long res = 0;
        int n = inventory.size();

        for (int i = n - 1; i >= 0 && orders > 0; i--) {
            long long diff = inventory[i] - (i > 0 ? inventory[i - 1] : 0);
            long long cnt = (n - i); // number of colors at this level
            long long x = min((long long)orders, cnt * diff);

            long long r = inventory[i];
            long long l = r - x / cnt;

            // sum from l+1 to r
            res += (r * (r + 1) / 2 - l * (l + 1) / 2) * cnt;
            res %= mod;

            // handle remainder
            res += 1LL * l * (x % cnt);
            res %= mod;

            orders -= x;
        }
        return (int)res;
    }
};
