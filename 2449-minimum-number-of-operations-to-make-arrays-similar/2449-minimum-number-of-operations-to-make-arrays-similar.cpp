using LL = long long;
class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        vector<LL> en, on, et, ot;
        int n = nums.size();
        for(int i = 0; i < n; ++i) {
            if(nums[i] & 1) on.push_back(nums[i]);
            else en.push_back(nums[i]);
            
            if(target[i] & 1) ot.push_back(target[i]);
            else et.push_back(target[i]);
        }
        

        return count(en, et) + count(on, ot);
    
    }
    
    LL count(vector<LL>& nums, vector<LL>& targets) {
        int n = nums.size();
        LL res= 0;
        sort(nums.begin(), nums.end());
        sort(targets.begin(), targets.end());
        for(int i = 0; i < n; ++i) {
            if(nums[i] > targets[i]) res += (nums[i] - targets[i]) / 2;
        }
        return res;
    }
    

};