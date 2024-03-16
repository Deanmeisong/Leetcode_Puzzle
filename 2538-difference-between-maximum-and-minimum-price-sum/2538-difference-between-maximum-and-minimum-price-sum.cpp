using LL = long long;
class Solution {
public:
    vector<int> next[100005];
    LL sum1[100005];
    LL sum2[100005];
    LL ret = 0;
    long long maxOutput(int n, vector<vector<int>>& edges, vector<int>& price) {
        if(n == 1) return 0;
        for(auto e : edges) {
            next[e[0]].push_back(e[1]);
            next[e[1]].push_back(e[0]);
        }
        dfs(0, -1, price);
        dfs2(0, -1, price);
        return ret;
    }
    
    void dfs(int cur, int parent, vector<int>& price) {
        if(next[cur].size() == 1 && next[cur][0] == parent) {
            sum1[cur] = 0; sum2[cur] = price[cur]; return;
        }
        LL maxSum1 = INT_MIN; LL maxSum2 = INT_MIN;
        for(int nxt : next[cur]) {
            if(nxt == parent) continue;
            dfs(nxt, cur, price);
            maxSum1 = max(maxSum1, sum1[nxt]);
            maxSum2 = max(maxSum2, sum2[nxt]);
        }
        sum1[cur] = price[cur] + maxSum1;
        sum2[cur] = price[cur] + maxSum2;
  
    }
    
    void dfs2(int cur, int parent, vector<int>& price) {
        vector<pair<LL,int>> arr1;
        vector<pair<LL,int>> arr2;
        
        LL ans = sum1[cur];
        // ans = max(ans, sum2[cur] - price[cur]);
        
        if(cur != 0) ans = max(ans, sum2[cur]);
        
        for(int nxt : next[cur]) {
            if(nxt == parent) continue;
            arr1.push_back({sum1[nxt], nxt});
            arr2.push_back({sum2[nxt], nxt});
            dfs2(nxt, cur, price);
        }
        
        sort(arr1.rbegin(), arr1.rend());
        sort(arr2.rbegin(), arr2.rend());
        
        if(arr1.size() >= 2) {
            if(arr1[0].second != arr2[0].second) ans = max(ans, arr1[0].first + arr2[0].first + price[cur]);
            else ans = max(ans, max(arr1[0].first + arr2[1].first, arr2[0].first + arr1[1].first) + price[cur]);
        }
        ret = max(ret, ans);
          
    }
    
};