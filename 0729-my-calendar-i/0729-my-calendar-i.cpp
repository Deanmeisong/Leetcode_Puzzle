class MyCalendar {
public:
    vector<pair<int, int>> books;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for(auto b : books) {
            if(max(b.first, start) < min(b.second, end)) return false;
        }
        books.push_back({start, end});
        return true;

    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */