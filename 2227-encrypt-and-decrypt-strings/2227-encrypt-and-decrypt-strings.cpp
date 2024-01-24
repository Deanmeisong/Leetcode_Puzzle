class Encrypter {
public:
    unordered_map<char, string> Map;
    unordered_map<string, int> count;
    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dictionary) {
        for(int i = 0; i < keys.size(); ++i) Map[keys[i]] = values[i];
        for(string& d : dictionary) {
            string t = encrypt(d);
            if(t != "") ++count[t];
        }
    }
    
    string encrypt(string word1) {
        string t = "";
        for(char c : word1) {
            if(Map.find(c) == Map.end()) return "";
            t += Map[c];
        }
        return t;
    }
    
    int decrypt(string word2) {
        return count[word2];
    }
};

/**
 * Your Encrypter object will be instantiated and called as such:
 * Encrypter* obj = new Encrypter(keys, values, dictionary);
 * string param_1 = obj->encrypt(word1);
 * int param_2 = obj->decrypt(word2);
 */