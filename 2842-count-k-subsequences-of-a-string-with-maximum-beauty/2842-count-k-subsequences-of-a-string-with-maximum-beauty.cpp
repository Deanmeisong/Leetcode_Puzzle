using LL = long long;
class Solution {
public:
    int k = 0;
    int beauty = 0;
    LL global = 0;
    LL M = 1e9 + 7;
    
    void dfs(int curPos, int picked, int curBeauty, LL ret, vector<int>& count) {
        if (picked > k) return ;
        if(curBeauty > beauty) return;
        if(picked == k && curBeauty == beauty) {
            global = (global + ret) % M;
            return;
        }
        if(curBeauty + accumulate(count.begin() + curPos, count.end(), 0) < beauty) return;

        for(int i = curPos; i < count.size(); ++i) {
            dfs(i + 1, picked + 1, curBeauty + count[i], (ret * count[i]) % M, count);
        }


    }
    
    int countKSubsequencesWithMaxBeauty(string s, int k) {
        this->k = k;
        unordered_map<char, int> Map;
        for(char ch : s) Map[ch] += 1;
        vector<int> count;
        for(auto [ch, freq] : Map) count.push_back(freq);
        sort(count.rbegin(), count.rend());
        if (count.size() <k) return 0;                

        for(int i = 0; i < k; ++i) beauty += count[i];
        dfs(0, 0, 0, 1, count);
        
        return global;
    }
};