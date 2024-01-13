class Solution {
public:
    vector<int> children[100005];
    int setId[100005];
    vector<unordered_set<int>> setList;
    vector<int> nums;
    vector<int> rets;
    
    vector<int> smallestMissingValueSubtree(vector<int>& parents, vector<int>& nums) {
        
        this->nums = nums;
        int n = parents.size();
        for (int i=1; i<n; i++)        
            children[parents[i]].push_back(i);

        rets.resize(n);
        dfs(0);
        return rets;
    }
    
    void dfs(int node) {
        if(children[node].empty()) {
            setId[node] = setList.size();
            setList.push_back({nums[node]});
            rets[node] = nums[node] == 1 ? 2 : 1;
        } else {
            for(int child : children[node])
                dfs(child);
            
            int maxSize = 0; int maxId;
            for(int child : children[node]) {
                if(setList[setId[child]].size() > maxSize) {
                    maxSize = setList[setId[child]].size();
                    maxId = setId[child];
                }
            }
            setId[node] = maxId;
            setList[maxId].insert(nums[node]);
            
            for(int child : children[node]) {
                if(setId[child] == maxId) continue;
                for(int x : setList[setId[child]])
                    setList[maxId].insert(x);
            }
            
            int maxMissing = 0;
            for(int child : children[node])
                maxMissing = max(maxMissing, rets[child]);
            int x = maxMissing;
            
            while(setList[maxId].find(x) != setList[maxId].end()) ++x;
            rets[node] = x;
            
        }
        
        
    }
};