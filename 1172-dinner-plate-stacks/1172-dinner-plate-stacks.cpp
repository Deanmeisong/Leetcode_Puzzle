class DinnerPlates {
public:
    DinnerPlates(int capacity) {
        this->capacity_ = capacity;
    }
    
    void push(int val) {
        int index = aval_.empty() ? stacks_.size() : *begin(aval_);
        if(index == stacks_.size()) stacks_.emplace_back();
        stack<int>& s = stacks_[index];
        s.push(val);
        if(s.size() == capacity_) aval_.erase(index);
        else if(s.size() == 1) aval_.insert(index);
    }
    
    int pop() {
        return popAtStack(stacks_.size() - 1);
    }
    
    int popAtStack(int index) {
        if(index < 0 || index >= stacks_.size() || stacks_[index].empty()) return -1;
        stack<int>& s = stacks_[index];
        int val = s.top(); s.pop();
        if(s.size() == capacity_ - 1) aval_.insert(index);
        auto it = prev(end(aval_));
        while (stacks_.size() && stacks_.back().empty()) {
          stacks_.pop_back();
          aval_.erase(it--);
        }
        return val;
        
    }
    
    int capacity_;
    set<int> aval_;
    vector<stack<int>> stacks_;
};

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates* obj = new DinnerPlates(capacity);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAtStack(index);
 */