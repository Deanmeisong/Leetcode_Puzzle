class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.length();
        vector<int> l(26, INT_MAX); vector<int> r(26, INT_MIN);
        for(int i = 0; i < n; ++i) {
            l[s[i] - 'a'] = min(l[s[i] - 'a'], i);
            r[s[i] - 'a'] = max(r[s[i] - 'a'], i);
        }
        
        function<int(int)> extend = [&](int i) -> int{
            int p = r[s[i] - 'a'];
            for(int j = i; j <= p; ++j) {
                if(l[s[j] - 'a'] < i) return -1;
                p = max(p, r[s[j] - 'a']);
            }
            return p;
        };
        
        int last = -1;
        vector<string> ans;
        for(int i = 0; i < n; ++i) {
            if(i != l[s[i] - 'a']) continue;
            int p = extend(i);
            if(p == -1) continue;
            if(i > last) ans.push_back("");
            ans.back() = s.substr(i, p - i + 1);
            last = p;
            
        }
        return ans;
    }
};