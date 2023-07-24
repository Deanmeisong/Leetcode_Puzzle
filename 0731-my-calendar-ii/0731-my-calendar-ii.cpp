class MyCalendar {
public:
    set<pair<int, int>> books;
    bool check(int start, int end) {
        // auto it = books.lower_bound({start, end});
        // if(it != books.end() and it->first < end) return false;
        // if(it != books.begin() and start < (--it)->second) return false;
        // books.insert({start, end});
        // return true;
        auto it = books.lower_bound({start, end});
        if(it != books.end() and end > it->first) return false;
        if(it!= books.begin() and start < (--it)->second) return false;
        books.insert({start, end});
        return true;
    }
};

class MyCalendarTwo {
public:
    vector<pair<int, int>> books;
    MyCalendarTwo() {}
    
    bool book(int start, int end) {
        MyCalendar overLap;
        for(auto b : books) {
            if(max(start, b.first) < min(end, b.second)) {
                auto p = getPair(start, end, b.first, b.second);
                if(!overLap.check(p.first, p.second)) return false;
            }
        }
        books.push_back({start, end});
        return true;
        
    }
    
    pair<int, int> getPair(int s1, int e1, int s2, int e2) {
        return {max(s1, s2), min(e1, e2)};
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */