class MyCalendar {
public:
    MyCalendar() {
        
    }
    map<int,int> intervals;
    bool book(int startTime, int endTime) {
        auto it = intervals.upper_bound(startTime);
        if(it == intervals.end() || it->second>=endTime){
            intervals[endTime] = startTime;
            return true;
        }
        return false;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */