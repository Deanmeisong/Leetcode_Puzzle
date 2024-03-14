class Graph {
    int n;
    int dp[100][100];
public:
    Graph(int n, vector<vector<int>>& edges) {
        this->n = n;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                dp[i][j] = INT_MAX/3;
            }
            dp[i][i] = 0;
        }
        
        for(auto e : edges) {
            int a = e[0]; int b = e[1]; int w = e[2];
            dp[a][b] = w;
        }
        
        for(int k = 0; k < n; ++k)
            for(int i = 0; i < n; ++i)
                for(int j = 0; j < n; ++j)
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
    
    }
    
    void addEdge(vector<int> edge) {
        int a = edge[0], b = edge[1], w = edge[2];
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                dp[i][j] = min(dp[i][j], dp[i][a] + w + dp[b][j]);
    }
    
    int shortestPath(int node1, int node2) {
        if(dp[node1][node2] == INT_MAX/3) return -1;
        else return dp[node1][node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */