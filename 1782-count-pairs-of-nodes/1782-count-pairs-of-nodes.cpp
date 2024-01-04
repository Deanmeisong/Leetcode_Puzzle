class Solution {
public:
    vector<int> countPairs(int n, vector<vector<int>>& edges, vector<int>& queries) {
        vector<int> count(n);
        unordered_map<long, int> edgeCount;
        int m = 20001;
        vector<int> ret;
        
        for(auto e : edges) {
            int a = min(e[0] - 1, e[1] - 1);
            int b = max(e[0] - 1, e[1] - 1);
            count[a]++; count[b]++;
            edgeCount[a*m+b]++;
        }
        
        auto count2 = count;
        sort(count2.begin(), count2.end());
        
        for(int q : queries) {
            int j = n - 1;
            int sum = 0;
            for(int i = 0; i < n; ++i) {
                if(i >= j) sum += n - i - 1;
                else {
                    while(i < j && count2[i] + count2[j] > q) --j;
                    sum += n - j - 1;
                }
            }
            
            
            
            for(auto [idx, cnt] : edgeCount) {
                int a = idx / m; int b = idx % m;
                if(count[a] + count[b] > q && count[a] + count[b] - cnt <= q) --sum; 
            }
            
            ret.push_back(sum);
        }
        
        return ret;
    }
};