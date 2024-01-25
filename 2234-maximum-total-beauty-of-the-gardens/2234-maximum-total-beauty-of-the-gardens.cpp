using LL = long long;
class Solution {
public:
    long long maximumBeauty(vector<int>& flowers, long long newFlowers, int target, int full, int partial) {
        sort(flowers.begin(), flowers.end());
        LL ret0 = 0;
        while(flowers.size() > 0 && flowers.back() >= target) {
            ret0 += full;
            flowers.pop_back();
        }
        if(flowers.size() == 0) return ret0;
        

        LL n = flowers.size();
        vector<LL> diff(n);
        vector<LL> presum(n);
        
        for(LL i = 0; i < n; ++i) presum[i] = (i == 0 ? 0 : presum[i - 1]) + flowers[i];
        for(LL i = 0; i < n; ++i) diff[i] = flowers[i] * (i + 1) - presum[i];
       
        LL ret = 0;
        
        for(LL i = n - 1; i >= 0; --i) {
            if(newFlowers < 0) break;
            if(presum[i] + newFlowers >= (LL)(target - 1) * (i + 1)) {
                ret = max(ret, (LL)(target - 1) * partial + (LL)(full * (n - 1 - i)));
            } else {
                auto iter = upper_bound(diff.begin(), diff.begin() + i + 1, newFlowers);
                int k = prev(iter) - diff.begin();
                LL each = (LL)(presum[k] + newFlowers) / (LL)(k + 1);
                ret = max(ret, each * partial + (LL)(full * (n - 1 - i)));
            }
            newFlowers -= (target - flowers[i]);
        }
        
        
        if(newFlowers >= 0) ret = max(ret, full * n);
        return ret + ret0;
    }
};