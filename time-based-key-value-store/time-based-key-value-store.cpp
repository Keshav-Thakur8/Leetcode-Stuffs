class TimeMap {
public:
    /** Initialize your data structure here. */
    unordered_map<string, vector<pair<string, int>>> m;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        vector<pair<string, int>>& v = m[key];
        int n = v.size();
        
        //corner case
        if(n == 0) {
            return "";
        }
        
        int si = 0, ei = n-1;
        int mid;
        while(si < ei) {
            mid = si + (ei-si+1)/2;
            
            if(v[mid].second > timestamp) {
                ei = mid-1;
            }
            else {
                si = mid;
            }
        }
        if(v[si].second <= timestamp)
            return v[si].first;
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */