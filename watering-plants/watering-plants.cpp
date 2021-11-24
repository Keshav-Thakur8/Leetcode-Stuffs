class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int n = plants.size();
        int cap = capacity;
        int ans = 0;
        for(int i=0 ; i<n ; i++) {
            //if you have enough water for plants
            if(plants[i] <= cap) {
                ans++;
            }
            //if you dont have enough water for plants refill it
            else {
                ans += i;
                ans += i+1;
                cap = capacity;
            }
            cap -= plants[i];
        }
        return ans;
    }
};