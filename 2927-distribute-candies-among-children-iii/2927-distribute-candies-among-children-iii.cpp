using LL = long long;
class Solution {
public:
    long long distributeCandies(int n, int limit) {

        function<LL(int)> comb = [&](int m) {
          return (1LL) * m * (m - 1) / 2;
        };
        if(n > limit * 3) return 0;
        LL res = comb(n + 2);
        if(n > limit) res -= 3*comb(n - limit + 1);
        if(n > 2*limit) res += 3*comb(n - 2 * limit);
        return res;
    }
};