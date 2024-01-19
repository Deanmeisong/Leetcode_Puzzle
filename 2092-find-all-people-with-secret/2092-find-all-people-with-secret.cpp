class Solution {
public:
    int father[100001];
    // vector<int> father;
    int ff(int x) {
        while(father[x] != x) {
            father[x] = father[father[x]];
            x = father[x];
        }
        return x;
    }
    void un(int x, int y) {
        x = ff(x); y = ff(y);
        if(x < y) father[y] = x;
        else father[x] = y;
    }
    static bool cmp(vector<int>& a, vector<int>& b) {
        return a[2] < b[2];
    }
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        for(int i = 0; i < n; ++i) father[i] = i;
        sort(meetings.begin(), meetings.end(), cmp);

        unordered_set<int> Set;
        Set.insert(0); Set.insert(firstPerson);
        father[firstPerson] = 0;
        for(int i = 0; i < meetings.size(); ++i) {
            unordered_set<int> tmp;
            int j = i;
            for(; j < meetings.size() && meetings[j][2]==meetings[i][2]; ++j) {
                int a = meetings[j][0]; int b = meetings[j][1];
                tmp.insert(a); tmp.insert(b);
                int af = ff(a); int bf = ff(b);
                if(af != bf) un(a, b);
            }
                      
            for(auto x : tmp) {
                if(ff(x) != 0) father[x] = x;
                else Set.insert(x);
            }
            
            i = j - 1;
        }
        
        vector<int>rets(Set.begin(), Set.end());
        return rets;
        
    }
};