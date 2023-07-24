class MyCalendar {
public:
    vector<pair<int, int>> overLaps;
    bool check(pair<int, int> meeting) {
        for(auto o : overLaps) {
            if(max(o.first, meeting.first) < min(o.second, meeting.second)) {
                return false;
            }
        }
        overLaps.push_back(meeting);
        return true;
    }
};

class MyCalendarTwo {
public:
    vector<pair<int, int>> books;
    MyCalendarTwo() {}
    
    bool book(int start, int end) {
        MyCalendar overlap;
        for(auto book : books) {
            if(max(book.first, start) < min(book.second, end)) {
                auto p = getPair(start, end, book.first, book.second);
                if(!overlap.check(p)) return false;
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