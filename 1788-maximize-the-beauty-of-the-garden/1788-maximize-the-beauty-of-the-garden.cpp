class Solution {
public:
    int maximumBeauty(vector<int>& flowers) {
        unordered_map<int, int> m;
        int res = INT_MIN;
        int sum = 0;
        for(int b : flowers) {
            if(m.count(b) > 0) res = max(res, sum - m[b] + 2*b);
            if(b > 0) sum += b;
            if(m.count(b) == 0) m[b] = sum;
        }
        return res;
    }
};