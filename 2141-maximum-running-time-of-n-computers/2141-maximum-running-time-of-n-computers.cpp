class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long left = 0, right = LLONG_MAX / n;
        while(left < right) {
            long long m = right - (right - left) / 2;
            if(check(m, n, batteries)) left = m;
            else right = m - 1;
        }
        return left;
    }
    
    bool check(long long t, int n, vector<int>& batteries) {
        long long sum = 0;
        for(int& b : batteries) {
            sum += min((long long)b, t);
            if(sum >= t * n) return true;
        }
        return false;
    }
};