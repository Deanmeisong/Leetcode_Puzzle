class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        unordered_map<int, int> freq;
        for(string w : words) {
            int mask = 0;
            for(int i = 0; i < w.length(); ++i) {
                mask |= (1 << (w[i] - 'a'));
            }
            ++freq[mask];
        }
        
        vector<int> res;
        for(string p : puzzles) {
            int count = 0;            
            int l = p.length() - 1;
            for(int i = 0; i < (1 << l); ++i) {
                int mask = 1 << (p[0] - 'a');
                for(int j = 0; j < l; ++j) {
                    if((1<<j) & i) mask |= (1 << (p[j + 1] - 'a'));
                }
                auto it = freq.find(mask);
                if(it != freq.end()) {
                    count += it->second;
                }
            }
            res.push_back(count);
        }
        
        return res;
    }
};