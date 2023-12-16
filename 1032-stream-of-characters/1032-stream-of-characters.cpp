class StreamChecker {
    class TrieNode {
    public:
        TrieNode* next[26];
        bool isEnd;
        TrieNode() {
            for(int i = 0; i < 26; ++i) next[i] = NULL;
            isEnd = false;
        }
    };
public:
    TrieNode* root;
    string str;
    
    StreamChecker(vector<string>& words) {
        root = new TrieNode();
        for(auto word : words)
            addWord(word);
    }
    
    bool query(char letter) {
        str.push_back(letter);
        return find();
    }
    
    void addWord(string word) {
        TrieNode* node = root;
        int n = word.size();
        for(int i = n - 1; i >= 0; --i) {
            char ch = word[i];
            if(node->next[ch - 'a'] == NULL) node->next[ch - 'a'] = new TrieNode();
            node = node->next[ch - 'a'];
        }
        node->isEnd = true;
    }
    
    bool find() {
        int n = str.size();
        TrieNode* node = root;
        for(int i = n - 1; i >= 0; --i) {
            char ch = str[i];
            if(node->next[ch - 'a'] != NULL) {
                node = node->next[ch - 'a'];
                if(node->isEnd == true) return true;
            } else return false;
        }
        return false;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */