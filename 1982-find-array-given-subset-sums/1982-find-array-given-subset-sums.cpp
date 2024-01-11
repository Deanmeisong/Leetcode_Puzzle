class Solution {
public:
    vector<int> recoverArray(int n, vector<int>& sums) {
        vector<int> rets;
        if(dfs(sums, n, rets)) return rets;
        return {};
    }
    
    bool dfs(vector<int> sums, int n, vector<int>& rets) {
        if(n == 1) {
            if(sums[0] != 0 && sums[1] != 0) return false;
            rets.push_back(sums[0] == 0 ? sums[1] : sums[0]);
            return true;
        }
        
        int k = sums.size();
        std :: nth_element(sums.begin(), sums.begin() + k - 1, sums.end());
        std :: nth_element(sums.begin(), sums.begin() + k - 2, sums.end());
        int x = sums[k - 1] - sums[k - 2];
        
        multiset<int> Set1(sums.begin(), sums.end());
        vector<int> sums1;
        for(int i = 0; i < k / 2; ++i) {
            int num = *Set1.rbegin();
            if(Set1.find(num - x) == Set1.end()) break;
            Set1.erase(Set1.lower_bound(num - x));
            Set1.erase(Set1.lower_bound(num));
            sums1.push_back(num - x);
        }
        if(sums1.size() == k / 2) {
            rets.push_back(x);
            if(dfs(sums1, n - 1, rets)) return true;
            rets.pop_back();
        }
        
        x = -x;
        multiset<int> Set2(sums.begin(), sums.end());
        vector<int> sums2;
        for(int i = 0; i < k / 2; ++i) {
            int num = *Set2.begin();
            if(Set2.find(num - x) == Set2.end()) break;
            Set2.erase(Set2.lower_bound(num - x));
            Set2.erase(Set2.lower_bound(num));
            sums2.push_back(num - x);
        }
        if(sums2.size() == k / 2) {
            rets.push_back(x);
            if(dfs(sums2, n - 1, rets)) return true;
            rets.pop_back();
        }
    
        
        return false;
    }
};