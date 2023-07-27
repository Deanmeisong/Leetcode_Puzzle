class PhoneDirectory {
public:
    vector<bool> used;
    PhoneDirectory(int maxNumbers) {
        used = vector<bool>(maxNumbers, false);
    }
    
    int get() {
        for(int i = 0; i < used.size(); ++i) {
            if(!used[i]) {
                used[i] = true;
                return i;
            }
        }
        return -1;
    }
    
    bool check(int number) {
        return !used[number];
    }
    
    void release(int number) {
        used[number] = false;
    }
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory* obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj->get();
 * bool param_2 = obj->check(number);
 * obj->release(number);
 */