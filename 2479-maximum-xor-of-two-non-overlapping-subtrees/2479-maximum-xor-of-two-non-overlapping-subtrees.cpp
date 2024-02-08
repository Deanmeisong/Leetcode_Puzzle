using ll = long long;

class Trie {
public:
    vector<Trie*> children;
    string v;
    Trie(): children(2) {}
    
    void insert(ll x) {
        Trie* node = this;
        for(int i = 47; ~i; --i) {
            int v = (x >> i) & 1;
            if(node->children[v] == NULL) node->children[v] = new Trie();
            node = node->children[v];
        }
    }
    
    ll search(ll x) {
        ll res = 0;
        Trie* node = this;
        for(int i = 47; ~i; --i) {
            if(node == NULL) return res;
            int v = (x >> i) & 1;
            if(node->children[v ^ 1] != NULL) {
                res = res << 1 | 1;
                node = node->children[v ^ 1];
            } else {
                res = res << 1;
                node = node->children[v];
            }
        }
        return res;
    }
};

class Solution {
public:
    long long maxXor(int n, vector<vector<int>>& edges, vector<int>& values) {  
        vector<ll> s(n);
        vector<vector<int>> g(n);
        for(auto& e : edges) {
            g[e[0]].emplace_back(e[1]);
            g[e[1]].emplace_back(e[0]);
        } 
        
        
        function<ll(int, int)> dfs = [&](int cur, int parent)->ll{
            ll t = values[cur];
            for(int nxt : g[cur]) {
                if(nxt == parent) continue;
                t += dfs(nxt, cur);
            }
            s[cur] = t;
            return t;
        };
        dfs(0, -1);
        Trie root;
        ll ans = 0;
        
        function<void(int, int)> dfs2 = [&](int cur, int parent) {
            ans = max(ans, root.search(s[cur]));
            for(int nxt : g[cur]) {
                if(nxt == parent) continue;
                dfs2(nxt, cur);
            }
                root.insert(s[cur]);
        };
        dfs2(0, -1);

        return ans;

    }
};