class Solution {
public:
    int romanToInt(string s) {
        int n = s.size();
        unordered_map<char,int> mp;
        mp.insert({'I',1});
        mp.insert({'V',5});
        mp.insert({'X',10});
        mp.insert({'L',50});
        mp.insert({'C',100});
        mp.insert({'D',500});
        mp.insert({'M',1000});
        int ans = 0;
        int prev = INT_MIN;
        for(int i=n-1 ; i>=0 ; i--) {
            int x = mp[s[i]];
            //this will handle all the six instances where subtraction is used
            if(x < prev) {
                ans -= x;
            }
            else {
                ans += x;
            }
            prev = x;
        }
        return ans;
    }
};