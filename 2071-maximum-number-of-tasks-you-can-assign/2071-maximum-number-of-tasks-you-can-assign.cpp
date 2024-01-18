class Solution {
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());
        int left = 0, right = tasks.size();
        while(left < right) {
            int mid = right - (right - left) / 2;
            if(check(tasks, workers, pills, strength, mid)) left = mid;
            else right = mid - 1;
        }
        return left;
    }
    
     bool check(vector<int>& tasks, vector<int>& workers, int pills, int strength, int mid) {
         if(tasks.size() < mid) return false;
         if(workers.size() < mid) return false;
         multiset<int> Set(workers.begin(), workers.end());
         for(int i = mid - 1; i >= 0; --i) {
             if(tasks[i] <= *Set.rbegin()) {
                 Set.erase(prev(Set.end()));
             } else {
                 if(pills == 0) return false;
                 auto it = Set.lower_bound(tasks[i]-strength);
                 if(it == Set.end()) return false;
                 Set.erase(it);
                 --pills;
             }
         }
         return true;
     }

};