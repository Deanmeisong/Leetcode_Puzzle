class Solution {
public:
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& o) {
        int same = 0;
        vector<double> ps;
        for(auto p : points) {
            if(p[0] == o[0] && p[1] == o[1]) ++same;
            else {
                ps.push_back(atan2(p[0] - o[0], p[1] - o[1]));
            }
        }

        sort(ps.begin(), ps.end());
        
        int n = ps.size();
        
        for(int i = 0; i < n; ++i) {
            ps.push_back(ps[i] + 2 * M_PI);
        }
        
        int l = 0, ans = 0;
        double fov = angle * M_PI / 180;
        for(int r = 1; r < ps.size(); ++r) {
            if((ps[r] - ps[l]) > fov) ++l;
            ans = max(ans, r - l + 1);
        }
        
        return ans + same;
    }
};