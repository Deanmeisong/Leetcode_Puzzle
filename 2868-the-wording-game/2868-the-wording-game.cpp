class Solution {
public:
    bool canAliceWin(vector<string>& a, vector<string>& b) {
        string w = a[0]; int i = 1, j = 0, k = 1;
        while(1) {
            if(k == 1) {
                if(j == b.size()) return true;
                if(w[0] == b[j][0] && w < b[j] || b[j][0] - w[0] == 1) {
                    w = b[j];
                    k ^= 1;
                }
                ++j;
            } else {
                if(i == a.size()) return false;
                if(w[0] == a[i][0] && w < a[i] || a[i][0] - w[0] == 1) {
                    w = a[i];
                    k ^= 1;
                }
                ++i;
            }
        }
    }
};