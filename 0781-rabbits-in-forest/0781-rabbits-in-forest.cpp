class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int res = 0, l = 0, r = 0, n = answers.size();
        sort(begin(answers), end(answers));
        while(l < n) {
            while(r < n && answers[l] == answers[r]) ++r;
            int num = r - l;
            int val = answers[l];
            int set = num / (val + 1);
            int remains = num % (val + 1);
            res += set * (val + 1) + (remains == 0 ? 0 : val + 1);
            l = r;
        }
        return res;
    }
};