class Solution {
public:
    vector<int> relative[501];
    int isRelative[501][501];
    unordered_set<int> visited;
    unordered_set<int> nodeSet;
    int flag = 1;
    int checkWays(vector<vector<int>>& pairs) {
        for(auto p : pairs) {
            nodeSet.insert(p[0]);
            nodeSet.insert(p[1]);
            relative[p[0]].push_back(p[1]);
            relative[p[1]].push_back(p[0]);
            isRelative[p[0]][p[1]] = 1;
            isRelative[p[1]][p[0]] = 1;
        }
        
        vector<int>nodes(nodeSet.begin(), nodeSet.end());
        sort(nodes.begin(), nodes.end(), [&](int a, int b) -> bool {
            return relative[a].size() < relative[b].size();
        });
        
        int root = -1;
        
        for(int i = 0; i < nodes.size(); ++i) {
            int j = i + 1;
            while(j < nodes.size() && !isRelative[nodes[i]][nodes[j]]) ++j;
            if(j < nodes.size()) {
                for(auto rel : relative[nodes[i]]) 
                    if(rel != nodes[j] && isRelative[rel][nodes[j]] == 0) return 0;
                if(relative[nodes[i]].size() == relative[nodes[j]].size()) flag = 2;
            } else {
                if(root == -1) root = nodes[i];
                else return 0;
            }
        }

        return flag;
    }
    

};