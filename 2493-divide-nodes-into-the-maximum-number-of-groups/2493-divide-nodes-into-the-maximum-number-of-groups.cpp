class Solution {
public:
    vector<int> next[505];
    int magnificentSets(int n, vector<vector<int>>& edges) {
        for(auto e : edges) {
            next[e[0]].push_back(e[1]);
            next[e[1]].push_back(e[0]);
        }
        
        unordered_map<int, int> Map;
        for(int start = 1; start <= n; ++start) {
            int d = 0;
            int smallestId = INT_MAX;
            vector<int> level(505);
            
            queue<int> q;
            q.push(start);
            level[start] = 1;
            
            while(!q.empty()) {
                int len = q.size();
                ++d;
                
                while(len--) {
                    int cur = q.front();
                    q.pop();
                    smallestId = min(smallestId, cur);
                    
                    for(int nxt : next[cur]) {
                        if(level[nxt] == 0) {
                            level[nxt] = d + 1;
                            q.push(nxt);

                        } else if(level[nxt] == d) {
                            return -1;
                        }
                    }
                                           

                }
                
            }
            Map[smallestId] = max(Map[smallestId], d);
        }
        
        int ret = 0;
        for(auto [k, v] : Map)
            ret += v;
        return ret;
        
    }
};