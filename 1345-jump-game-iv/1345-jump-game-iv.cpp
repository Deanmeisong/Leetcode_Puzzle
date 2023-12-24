class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if(n == 1) return 0;
        int steps = 0;
        queue<int> q;
        vector<int> visited(n, 0);
        q.push(0);
        visited[0] = 1;
        
        unordered_map<int, vector<int>> Map;
        for(int i = 0; i < n; ++i) Map[arr[i]].push_back(i);
        
        while(!q.empty()) {
            int len = q.size();
            while(len--) {
                int cur = q.front(); q.pop();
                if(cur < n - 1 && visited[cur + 1] == 0) {
                    q.push(cur + 1);
                    visited[cur + 1] = 1;
                }
                if(cur > 0 && visited[cur - 1] == 0) {
                    q.push(cur - 1);
                    visited[cur - 1] = 1;
                }
                for(int nxt : Map[arr[cur]]) {
                    if(visited[nxt] == 0) {
                        q.push(nxt);
                        visited[nxt] = 1;
                    }
                }
                Map.erase(arr[cur]);                
            }
            steps++;
            if (visited[n-1] == 1)
            return steps;
        }
        
        return -1;
    }
};