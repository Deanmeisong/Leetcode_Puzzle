class Solution {
 public:
  int maximumPoints(vector<vector<int>>& edges, vector<int>& coins, int k) {
    const int n = coins.size();
    vector<vector<int>> g(n);
    vector<vector<int>> f(n, vector<int>(14, -1));

    for (const vector<int>& edge : edges) {
      const int u = edge[0];
      const int v = edge[1];
      g[u].push_back(v);
      g[v].push_back(u);
    }

    return dfs(g, 0, -1, coins, k, 0, f);
  }

  int dfs(const vector<vector<int>>& g, int i, int fa,
          const vector<int>& coins, int k, int j,
          vector<vector<int>>& f) {
    // All the children will be 0, so no need to explore.
    if (j > 13) return 0;
    if (f[i][j] != -1) return f[i][j];

    int a = (coins[i] >> j) - k;
    int b = coins[i] >> (j+1);

    for (const int c : g[i]) {
      if (c != fa) {
          a += dfs(g, c, i, coins, k, j, f);
          b += dfs(g, c, i, coins, k, j + 1, f);
      }

    }

    return f[i][j] = max(a, b);
  }
};