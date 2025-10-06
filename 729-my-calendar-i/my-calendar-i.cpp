class MyCalendar {
public:
    MyCalendar() {
        
    }
    map<int,int> intv;
    bool book(int startTime, int endTime) {
      auto it = intv.upper_bound(startTime);
      if(it == intv.end() || it->second >= endTime){
        intv[endTime] = startTime;
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