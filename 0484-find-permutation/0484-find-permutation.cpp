class Solution {
public:
    vector<int> findPermutation(string s) {
        vector<int> res;
        int n = s.size();
        for(int i = 0; i <= n; ++i)
            if(i == n or s[i] == 'I')
                for(int j = i + 1, len = res.size(); j > len; --j)
                    res.push_back(j);
        return res;
    }
};