class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        // if(changed.size()&1 != 0)return vector<int>{};
        // vector<int>res;
        // sort(changed.begin(),changed.end(),greater<int>());
        // unordered_map<int,int>mp;
        // for(int i=0;i<changed.size();i++){
        //     if(mp.find(changed[i]*2) != mp.end() && mp[changed[i]*2] != 0){
        //         res.push_back(changed[i]);
        //         mp[changed[i]*2]--;
        //     }
        //     else{
        //         mp[changed[i]]++;
        //     }
        // }
        // if(res.size()!=(changed.size()/2))
        //     return vector<int>{};
        // return res;
        
        int n = changed.size();
        vector<int> ans;
        if(n&1 != 0) {
            return ans;
        }
        sort(changed.begin(), changed.end());
        unordered_map<int, int> mp;
        for(int i=0 ; i<n ; i++) {
            mp[changed[i]]++;
        }
        for(int i=0 ; i<n ; i++) {
            if(mp.find(2*changed[i]) != mp.end() && mp[changed[i]] != 0 && mp[2*changed[i]] != 0 && changed[i] != 0) {
                ans.push_back(changed[i]);
                mp[changed[i]]--;
                mp[2*changed[i]]--;
            }
        
        }
        
        int cnt = mp[0];
        if(cnt & 1 != 0) {
            return {};
        }
        else {
            for(int i=0 ; i<cnt/2; i++) {
                ans.push_back(0);
            }
        }
        if(ans.size() != n/2) {
            return {};
        }
        return ans;
        // int size = n/2;
        // vector<int> hash(n,-1);
        // for(int i=0 ; i<n ; i++) {
        //     for(int j=i+1; j<n ; j++) {
        //         if(changed[j] == 2*changed[i] && hash[i] == -1 && hash[j] == -1) {
        //             ans.push_back(changed[i]);
        //             hash[i] = hash[j] = 0;
        //             size--;
        //         }
        //     }
        // }
        // if(size == 0) return ans;
        // return {};
    }
};