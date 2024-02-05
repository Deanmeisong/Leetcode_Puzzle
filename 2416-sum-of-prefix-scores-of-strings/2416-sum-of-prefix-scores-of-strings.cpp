class Solution {
    class TrieNode {
    public:
        TrieNode* next[26];
        int count = 0;
        TrieNode() {
            for(int i = 0; i < 26; ++i) next[i] = NULL;
            
        }
    };
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        TrieNode* root = new TrieNode();
        for(string w : words) {
            TrieNode* node = root;
            for(char c : w) {
                if(node->next[c - 'a'] == NULL) node->next[c - 'a'] = new TrieNode();
                node = node->next[c - 'a'];
                node->count++;
            }
        }
        
        vector<int> ret;
        
        for(string w : words) {
            TrieNode* node = root;
            int ans = 0;
            for(char c : w) {
                if(node->next[c - 'a'] == NULL) break;
                node = node->next[c - 'a'];
                ans += node->count;
            }
            ret.push_back(ans);
        }
        
        return ret;
    }
};