class MyCalendar {
public:
    map<int,int> mp;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto it = mp.lower_bound(start);
        
        //after the current event
        if(it != mp.end() && it->first < end) {
            return false;
        }
        
        //before the current event
        if(it != mp.begin()) {
            --it;
            if(it->second > start) {
                return false;
            }
            
        }
        mp[start] = end;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */