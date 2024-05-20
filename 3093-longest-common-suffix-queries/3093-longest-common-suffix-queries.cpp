class TrieNode {
public:
    int index;
    unordered_map<char, TrieNode*> children;
    
    TrieNode(int index = INT_MAX) : index(index) {}
};
class Trie {
private:
    TrieNode* root;
    vector<string> words;
    
    bool change(int i, int j) { 
        int n = words.size();
        return (0 <= j && j < n) && 
            (!(0 <= i && i < n) || 
             words[j].size() < words[i].size() || // or if less size
             (words[j].size() == words[i].size() && j < i)); // or if less index
    }
    
    int fillIndices(TrieNode* curr) {
        for (char ch = 'a'; ch <= 'z'; ch++) {
            int r = curr->children.find(ch) != curr->children.end()
                ? fillIndices(curr->children[ch]) : INT_MAX;
            if (change(curr->index, r)) {
                curr->index = r;
            }
        }
        return curr->index;
    }
    
public:
    Trie(vector<string>& words) : root(new TrieNode), words(words) {
        int n = words.size();
        for (int i = 0; i < n; i++) {
            insertSuffix(words[i], i);
        }
        fillIndices(root);
    }
    
    void insertSuffix(string& s, int index) {
        TrieNode* curr = root;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (curr->children.find(s[i]) == curr->children.end()) {
                curr->children[s[i]] = new TrieNode;
            }
            curr = curr->children[s[i]];
        }
        curr->index = min(curr->index, index);
    }
    
    int longestCommonSuffix(string& s) {
        TrieNode* curr = root;
        for (int i = s.size() - 1; i >= 0 && curr->children.find(s[i]) != curr->children.end(); i--) {
            curr = curr->children[s[i]];
        }
        return curr->index;
    }
};

class Solution {
public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        Trie trie(wordsContainer);
        vector<int> result;
        for (string& s: wordsQuery) {
            result.push_back(trie.longestCommonSuffix(s));
        }
        return result;
    }
};
