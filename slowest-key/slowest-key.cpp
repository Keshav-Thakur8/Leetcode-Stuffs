class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        int n = releaseTimes.size();
        int longPress = releaseTimes[0];
        char slowKey = keysPressed[0];
        for(int i=1 ; i<n ; i++) {
            int currTime = releaseTimes[i] - releaseTimes[i-1];
            if(currTime > longPress || (currTime == longPress && keysPressed[i] > slowKey)) {
                longPress = currTime;
                slowKey = keysPressed[i];
            }
        }
        return slowKey;
    }
};