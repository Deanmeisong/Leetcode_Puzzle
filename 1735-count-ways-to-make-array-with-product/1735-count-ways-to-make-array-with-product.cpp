typedef long long ll;
class Solution {
public:
    ll comb[10015][15];
    ll M = 1e9 + 7;
    vector<int> waysToFillArray(vector<vector<int>>& queries) {
        int maxK = 10000; int maxExp = 14;

        for (int i = 0; i <= (maxK+maxExp); ++i) 
        {
            comb[i][0] = 1;            
            for (int j = 1; j <= min(i, maxExp); ++j) 
            {
                comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % M;
            }
        }  
        
        vector<int> ret;
        for(auto q : queries) {
            int k = q[1]; int n = q[0];
            int ans = 1;
            for(int x = 2; x <= k; ++x) {
                int count = 0;
                while(k % x == 0) {
                    k /= x;
                    count++;
                }
                ans = ans * comb[n + count - 1][count] % M;
            }
            ret.push_back(ans);
        }
        return ret;
        
    }
};