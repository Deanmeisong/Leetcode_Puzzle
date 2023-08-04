struct CacheNode {
    int key; int value; int freq; long tick;
    bool operator < (const CacheNode& ch) const {
        if(freq < ch.freq) return true;
        if(freq == ch.freq) return tick < ch.tick;
        return false;
    }
};

class LFUCache {
private:
    int c_; int t_;
    unordered_map<int, CacheNode> m_;
    set<CacheNode> cache;
public:
    LFUCache(int capacity) {
        this->c_ = capacity; this->t_ = 0;
    }
    
    int get(int key) {
        auto it = m_.find(key);
        if(it == m_.cend()) return -1;
        int value = it->second.value;
        touch(it->second);
        return value;
    }
    
    void put(int key, int value) {
        if(c_ == 0) return;
        auto it = m_.find(key);
        if(it != m_.cend()) {
            it->second.value = value;
            touch(it->second);
            return;
        }
        
        if(m_.size() == c_) {
            const CacheNode& node = *cache.cbegin();
            m_.erase(node.key);
            cache.erase(node);
 
        }
        
        CacheNode ch{key, value, 1, ++t_};
        cache.insert(ch);
        m_[key] = ch;
    }
    
    void touch(CacheNode& ch) {
        cache.erase(ch);
        ++ch.freq;
        ch.tick = ++t_;
        cache.insert(ch);
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */