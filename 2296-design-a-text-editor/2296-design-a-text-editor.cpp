class TextEditor {
public:
    stack<char> st1;
    stack<char> st2;
    
    TextEditor() {
        
    }
    
    void addText(string text) {
        for(char c : text) st1.push(c);
    }
    
    int deleteText(int k) {
        int count = min(k, (int)st1.size());
        int ret = count;
        while(!st1.empty() && ret > 0) {
            st1.pop();
            --ret;
        }
        return count;
    }
    
    string cursorLeft(int k) {
        int count = min(k, (int)st1.size());
        while(!st1.empty() && count > 0) {
            st2.push(st1.top());
            st1.pop();
            --count;
        }
        count = min(10, (int)(int)st1.size());
        string res;
        while(!st1.empty() && count > 0) {
            res.push_back(st1.top());
            st1.pop();
            --count;
        }
        reverse(res.begin(), res.end());
        for(char c : res) st1.push(c);
        return res;
    }
    
    string cursorRight(int k) {
        int count = min(k, (int)st2.size());
        while(!st2.empty() && count > 0) {
            st1.push(st2.top());
            st2.pop();
            --count;
        }
        count = min(10, (int)st1.size());
        string res;
        while(!st1.empty() && count > 0) {
            res.push_back(st1.top());
            st1.pop();
            --count;
        }
        reverse(res.begin(), res.end());
        for(char c : res) st1.push(c);
        return res;
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */