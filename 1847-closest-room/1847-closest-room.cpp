static bool cmp(vector<int>& a, vector<int>& b) {
    return a[1] > b[1];
};
class Solution {
public:
    vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries) {
        for(int i = 0; i < queries.size(); ++i) queries[i].push_back(i);
        int m = queries.size();
        vector<int> rets(m);
        sort(rooms.begin(), rooms.end(), cmp);
        sort(queries.begin(), queries.end(),cmp);
        int i = 0;
        set<int> Set;
        
        for(auto& q : queries) {
            while(i < rooms.size() && q[1] <= rooms[i][1]) {
                Set.insert(rooms[i][0]);
                ++i;
            }
            int ans = -1;
            int diff = INT_MAX;
            auto iter = Set.lower_bound(q[0]);
            if(iter != Set.end()) {
                if(*iter - q[0] < diff) {
                    diff = *iter - q[0];
                    ans = *iter;
                }
            }
            
            if(iter != Set.begin()) {
                iter = prev(iter,1);
                if (abs(*iter - q[0]) <= diff)
                {
                    diff = abs(*iter-q[0]);
                    ans = *iter;
                }
            }
            
            rets[q[2]] = ans;
        }
        
        return rets;
    }
};