class Solution {
public:
    int maxIncreasingGroups(vector<int>& A) {
        sort(A.begin(), A.end());
        long long tt = 0, ans = 0;
        for(int a : A) {
            tt += a;
            if(tt >= (ans+1)*(ans+2)/2) ++ans;
        }
        return ans;
    }
};