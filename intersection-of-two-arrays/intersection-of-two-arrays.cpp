class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_map<int,bool> m;
        for(int i=0 ; i<nums1.size() ; i++){
            m[nums1[i]] = true;
        }
        for(int j=0 ; j<nums2.size() ; j++){
            if(m[nums2[j]] == true)
                ans.push_back(nums2[j]);
                m[nums2[j]] = false;
        }
        return ans;
    }
};