class RandomizedSet {
public:
    /** Initialize your data structure here. */
    unordered_map<int,int> m;
    vector<int> v;
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        //check if already present
        if(m.find(val) != m.end()) {
            return false;
        }
        
        //insert in vector
        v.push_back(val);
        
        //insert in map
        m.insert({val, v.size()-1});
        
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(m.find(val) == m.end()) {
            return false;
        }
        
        //m[val] is the index where the element is present in v
        //swap with last element in the vector
        swap(v[v.size()-1], v[m[val]]);
        
        //update the index in the map for new element
        m[v[m[val]]] = m[val];
        
        //pop back from vector
        v.pop_back();
        
        //remove from vector
        m.erase(val);
        
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int idx = rand()%(v.size());
        return v[idx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */