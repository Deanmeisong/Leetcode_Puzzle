
class FileSystem {
    class TrieNode {
        public:
            bool isFile = false;
            map<string, TrieNode*> Map;
    };
    TrieNode* root;
    unordered_map<string, string> fileContent;
public:
    FileSystem() {
        root = new TrieNode();
    }
    
    vector<string> ls(string path) {
        TrieNode* node = root;
        int len = path.length();
        string str;
        for(int i = 1; i < len; ++i) {
            int i0 = i;
            while(i < len && path[i] != '/') ++i;
            str = path.substr(i0, i - i0);
            node = node->Map[str];
        }
        
        if(node->isFile) return {str};
        vector<string> res;
        for(auto a : node->Map) res.push_back(a.first);
        return res;
    }
    
    void mkdir(string path) {
        TrieNode* node = root;
        int len = path.length();
        string str;
        for(int i = 1; i < len; ++i) {
            int i0 = i;
            while(i < len && path[i] !='/') ++i;
            str = path.substr(i0, i - i0);
            if(node->Map.find(str) == node->Map.end()) {
                node->Map[str] = new TrieNode();
            }
            node = node->Map[str];
        }
    }
    
    void addContentToFile(string filePath, string content) {
        TrieNode* node = root;
        int len = filePath.length();
        string str;
        for(int i = 1; i < len; ++i) {
            int i0 = i;
            while(i < len && filePath[i] != '/') ++i;
            str = filePath.substr(i0, i - i0);
            if(node->Map.find(str) == node->Map.end()) {
                node->Map[str] = new TrieNode();
            }
            node = node->Map[str];
        }
        node->isFile = 1;
        fileContent[filePath] += content;
    }
    
    string readContentFromFile(string filePath) {
        return fileContent[filePath];
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * vector<string> param_1 = obj->ls(path);
 * obj->mkdir(path);
 * obj->addContentToFile(filePath,content);
 * string param_4 = obj->readContentFromFile(filePath);
 */