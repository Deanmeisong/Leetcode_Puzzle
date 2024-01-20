class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();
        queue<int> q;
        vector<int> visited(n);
        vector<int> depths(n, 1);
        vector<int> indegrees(n);
        
        for(int f : favorite) ++indegrees[f];
        
        for(int i = 0; i < n; ++i)
            if(indegrees[i] == 0) {q.push(i); visited[i] = 1;}
        
        while(!q.empty()) {
            int len = q.size();
            while(len--) {
                int cur = q.front(); q.pop();
                int nxt = favorite[cur];
            //                 indegrees[nxt]--;
            // if (indegrees[nxt]==0)            
            // {
            //     q.push(nxt);                                      
            //     visited[nxt] = 1;
            // }                
            // depths[nxt] = depths[cur]+1;
                if(--indegrees[nxt] == 0) {
                    q.push(nxt);
                    visited[nxt] = 1;
                }
                depths[nxt] = depths[cur] + 1;
            }
        }
        
        int maxCircle = 0, maxLink = 0;
        
        for(int i = 0; i < n; ++i) {
            if(visited[i]) continue;
            int count = 0;
            int j = i;
            while(visited[j] == 0) {
                ++count;
                visited[j] = 1;
                j = favorite[j];
            }
            
            if(count > 2) {
                maxCircle = max(count, maxCircle);
            } else if(count == 2) {
                maxLink += depths[i] + depths[favorite[i]];
            }

        }
        
        return max(maxCircle, maxLink);
    }
};