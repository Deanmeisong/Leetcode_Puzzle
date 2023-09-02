class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        std::sort(satisfaction.begin(), satisfaction.end(), std::greater<>());
        int res = 0, tmp = 0;
        for(int s : satisfaction) {
            if(tmp + s <= 0) break;
            tmp += s;
            res += tmp;
        }
        return res;
    }
};