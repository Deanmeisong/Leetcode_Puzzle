class Solution {
vector<int> nexts[100005];
vector<int> vals;
int ans = 0;
int n;
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        this->vals = vals;
        for(auto e : edges) {
            nexts[e[0]].push_back(e[1]);
            nexts[e[1]].push_back(e[0]);
        }
        dfs(0, -1);
        n = vals.size();
        return ans + n;
    }
    
    map<int, int> dfs(int cur, int parent) {
        map<int, int> count;
        count[vals[cur]]++;
        
        for(int child : nexts[cur]) {
            if(child == parent) continue;
            map<int, int> tmp = dfs(child, cur);
            
            auto iter = tmp.lower_bound(vals[cur]);
            tmp.erase(tmp.begin(), iter);
            
            if (tmp.size() > count.size())
            swap(tmp, count);
            
            for(auto& [val, freq] : tmp) 
                if(count.find(val) != count.end()) ans += freq * count[val];
            
            for(auto& [val, freq] : tmp) count[val] += freq;
            
        }
        
        return count;
    }
};