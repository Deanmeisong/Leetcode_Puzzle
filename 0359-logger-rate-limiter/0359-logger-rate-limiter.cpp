class Logger {
public:
    unordered_map<string, int> m;
    Logger() {
        
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        if(m.find(message) == m.end()) m[message] = 10 + timestamp;
        else {
            int t = m[message];
            if(timestamp < t) return false;
            m[message] = timestamp + 10;
        }
        return true;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */