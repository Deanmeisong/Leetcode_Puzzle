struct CacheNode {
    int key; int value; long tick; int freq;
    bool operator < (const CacheNode& cn) const {
        if(freq < cn.freq) return true;
        if(freq == cn.freq) return tick < cn.tick;
        return false;
    }
};
class LFUCache {
private:
    int capacity_;
    long tick_;
    unordered_map<int, CacheNode> m_;
    set<CacheNode> cs;
public:
    LFUCache(int capacity) {
        this->capacity_ = capacity; this->tick_ = 0;
    }
    
    int get(int key) {
        auto it = m_.find(key);
        if(it == m_.cend()) return -1;
        touch(it->second);
        return it->second.value;
    }
    
    void put(int key, int value) {
        if(capacity_ == 0) return;
        auto it = m_.find(key);
        if(it != m_.cend()) {
            it->second.value = value;
            touch(it->second);
            return;
        }
        
        if(m_.size() == capacity_) {
            const CacheNode& node = *cs.cbegin();
            m_.erase(node.key);
            cs.erase(node);
        }

        CacheNode node{key, value, ++tick_, 1};
        m_[node.key] = node;
        cs.insert(node);

    }
    
    void touch(CacheNode& ch) {
        cs.erase(ch);
        ++ch.freq;
        ch.tick = (++tick_);
        cs.insert(ch);
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */