class Solution {
public:
    int largestVariance(string s) {
        int n = s.length();
        set<int> Set(s.begin(), s.end());
        int ret = 0;
        for(char a : Set)
            for(char b : Set) {
                if(a == b) continue;
                int dpa = 0; int dpb = INT_MIN/2;
                for(int i = 0; i < n; ++i) {
                    if (s[i] == a)
                    {
                        dpa = dpa + 1;
                        dpb = dpb + 1;
                    }
                    else if (s[i] == b)
                    {
                        dpb = max(dpa-1, dpb-1);
                        dpa = 0;                        
                    }
                    ret = max(ret, dpb);
                }
                
            }
        
        return ret;
    }
};