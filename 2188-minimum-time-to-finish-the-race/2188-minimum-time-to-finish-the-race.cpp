using LL = long long;
class Solution {
public:
    static bool cmp(vector<int>& t1, vector<int>& t2) {
        if(t1[1] != t2[1]) return t1[1] < t2[1];
        else return t1[0] < t2[0];
    }
    

    int minimumFinishTime(vector<vector<int>>& tires, int changeTime, int numLaps) {
        sort(tires.begin(), tires.end(), cmp);
        vector<vector<int>> newTires;
        for(int i = 0; i < tires.size(); ++i) {
            if (!newTires.empty() && newTires.back()[0] <= tires[i][0])
                continue;
            newTires.push_back(tires[i]);
        }
        
        vector<double> minCost(min(20, numLaps+1), DBL_MAX);
        for(int i = 1; i < minCost.size(); ++i)
            for(int j = 0; j < newTires.size(); ++j)
                minCost[i] = min(minCost[i], cal(newTires[j], i));
        
        vector<double> dp(numLaps+1, DBL_MAX);
        dp[0] = 0;
        for(int i = 1; i <= numLaps; ++i)
            for(int j = i-1; j >= 0 && i-j < 20; --j)
                dp[i] = min(dp[i], dp[j] + (j==0 ? 0 : changeTime) + minCost[i-j]);
        return dp[numLaps];
    }
    
    double cal(vector<int>& t, int x) {
        int f = t[0]; int r = t[1];
        return f*(pow(r,x)-1)/(r-1);
    }
};