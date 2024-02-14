class Solution {
public:
    int minimumTime(vector<int>& hens, vector<int>& grains) {
        sort(hens.begin(), hens.end());
        sort(grains.begin(), grains.end());
        int left = 0, right = INT_MAX;
        while(left < right) {
            int mid = left + (right - left) / 2;
            if(isOK(hens, grains, mid)) right = mid;
            else left = mid + 1;
        }
        return left;

    }
    
    bool isOK(vector<int>& hens, vector<int>& grains, int time) {
        int j = 0;
        for(int i = 0; i < hens.size(); ++i) {
            int t = 0;
            if(hens[i] - grains[j] > time) return false;
            if(hens[i] > grains[j]) t = hens[i] - grains[j];
            else t = 0;
            while(j < grains.size() && grains[j] <= hens[i]) ++j;
            
            if(j == grains.size()) return true;
            if(time < 3*t) {
                while(j < grains.size() && (t + 2*(grains[j] - hens[i])) <= time) ++j;
            } else {
                while(j < grains.size() && (2*t + grains[j] - hens[i]) <= time) ++j;
            }
            
            if(j == grains.size()) return true;
            
        }
        return false;
    }
    
    
    // time - 2t > (time - t) / 2
};