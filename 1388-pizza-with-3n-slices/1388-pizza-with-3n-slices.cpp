class Solution {
public:
    int maxSizeSlices(vector<int>& slices) {
        int n = slices.size();
        return max(helper(0, n - 2, n / 3, slices), helper(1, n - 1, n / 3, slices));
    }
    
    int helper(int start, int end, int k, vector<int>& slices) {

        // int dp0[501][501]; 
        // int dp1[501][501];

        // for(int i = 0; i <= 500; ++i)
        //     for(int j = 0; j <= 500; ++j) {
        //         dp0[i][j] = 0; dp1[i][j] = 0;
        //     }

        
        vector<vector<int>> dp0(501, vector<int>(k + 1, 0));
        vector<vector<int>> dp1(501, vector<int>(k + 1, 0));
        
        dp0[start][0] = 0;
        dp1[start][1] = slices[start];

        for(int i = start + 1; i <= end; ++i)
            for(int j = 1; j <= min(k, i - start + 1); ++j) {
                dp0[i][j] = max(dp0[i - 1][j], dp1[i - 1][j]);
                dp1[i][j] = dp0[i - 1][j - 1] + slices[i];
            }
        
        return max(dp0[end][k], dp1[end][k]);
        
//              vector<int>dp0(k+1);
//         vector<int>dp1(k+1);
        
//         for (int i=start; i<=end; i++)
//             for (int j=min(k,i-start+1); j>=1; j--)
//             {
//                 dp0[j] = max(dp0[j], dp1[j]);
//                 dp1[j] = dp0[j-1] + slices[i];
//             }
        
//         return max(dp0[k], dp1[k]);
    }
};