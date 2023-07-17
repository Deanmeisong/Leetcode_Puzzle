class Solution {
public:
    int newInteger(int n) {
        vector<int> s;
        while(n) {
            s.push_back(n % 9);
            n /= 9;
        }
        int ans = 0;
        for(int i = s.size() - 1; i >= 0; --i) {
            ans = ans * 10 + s[i];
        }
        
        return ans;
    }
};