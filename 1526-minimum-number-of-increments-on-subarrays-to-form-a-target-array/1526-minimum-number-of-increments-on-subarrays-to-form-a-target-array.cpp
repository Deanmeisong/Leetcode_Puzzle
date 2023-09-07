class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int n = target.size();
        int count = target[n - 1];
        for(int i = n - 2; i >= 0; --i)
            count += max(0, target[i] - target[i + 1]);
        return count;
    }
};