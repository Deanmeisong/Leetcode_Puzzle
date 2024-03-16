class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        map<int, int> Map;
        for(int x : basket1) ++Map[x];
        for(int x : basket2) --Map[x];
        int minV = Map.begin()->first;
        vector<int> arr;
        for(auto [k, v] : Map) {
            if(v % 2 != 0) return -1;
            for(int i = 0; i < abs(v/2); ++i)
                arr.push_back(k);
        }
        
        sort(arr.begin(), arr.end());
        long long ans = 0;
        for(int i = 0; i < arr.size()/2; ++i)
            ans += min(2*minV, arr[i]);
        return ans;
    }
};