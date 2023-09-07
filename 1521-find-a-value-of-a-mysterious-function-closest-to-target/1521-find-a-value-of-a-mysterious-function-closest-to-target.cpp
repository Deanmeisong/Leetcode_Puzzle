class Solution {
public:
    int closestToTarget(vector<int>& arr, int target) {
        unordered_set<int> s;
        int res = INT_MAX;
        for(int i = 0; i < arr.size(); ++i) {
            unordered_set<int> s1;
            for(int x : s) s1.insert(x & arr[i]);
            s1.insert(arr[i]);
            for(int x : s1) res = min(res, abs(x - target));
            s = s1;
        }
        return res;
    }
};