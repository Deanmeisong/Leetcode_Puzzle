using LL = long long;
class Solution {
public:
    long long minimumMoney(vector<vector<int>>& transactions) {
        sort(transactions.begin(), transactions.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });
        
        LL hisLow, cur = 0;
        int costMaxGain = 0;
        
        for(auto t : transactions) {
            int cost = t[0], gain = t[1];
            if(cost <= gain) {
                costMaxGain = max(cost, costMaxGain);
            } else {
                cur -= cost;
                hisLow = min(cur, hisLow);
                cur += gain;
            }
        }
        
        cur -= costMaxGain;
        hisLow = min(cur, hisLow);
        
        return abs(hisLow);
    }
};