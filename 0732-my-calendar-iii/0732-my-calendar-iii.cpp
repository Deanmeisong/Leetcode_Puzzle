class MyCalendarThree {
public:
    map<int, int> meetings;
    MyCalendarThree() {}
    
    int book(int startTime, int endTime) {
        ++meetings[startTime];
        --meetings[endTime];
        int tmp = 0, res = 0;
        for(auto m : meetings) {
            tmp += m.second;
            res = max(res, tmp);
        }
        return res;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */