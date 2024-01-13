class Solution {
public:
    vector<int> children[100001];
    int q = 1;
    unordered_set<int> Set;
    
    void dfs(int node, vector<int>& rets) {
        rets[node] = 1;
        for(int child : children[node])
            dfs(child, rets);
    }
    
    
    void dfs2(int node, vector<int>& nums) {
        if(Set.find(nums[node]) != Set.end()) return;
        Set.insert(nums[node]);
        for(int child : children[node]) dfs2(child, nums);
    }
    
    vector<int> smallestMissingValueSubtree(vector<int>& parents, vector<int>& nums) {
        int n = parents.size();
        vector<int>val2node(100001, -1);

        vector<int> rets(n, 1);
        
        for(int i = 1; i < n; ++i) {
            if(parents[i] != -1) children[parents[i]].push_back(i);
        }
        
        for (int i=0; i<n; i++)
            val2node[nums[i]] = i;
        
        if(val2node[1] == -1) return rets;
        
        int node = val2node[1];
        
        for(int child : children[node])
            dfs(child, rets);
        
        while(node != 0) {
            int p = parents[node];
            for(int child : children[p])
                if(child != node) dfs(child, rets);
            node = p;
        }
        
        node = val2node[1];
        while(node != -1) {
            dfs2(node, nums);
            while(Set.find(q) != Set.end()) ++q;
            rets[node] = q;
            node = parents[node];
        }
        
        return rets;
    }
};