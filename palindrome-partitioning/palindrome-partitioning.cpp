class Solution {
public:
    bool isPalindrome(string&s){
        int start = 0;
        int end = s.size()-1;
        while(start<=end){
            if(s[start] != s[end])
                return false;
            start++;
            end--;
        }
        return true;
    }
    
    vector<vector<string>> res;
    
    void helper(string& s, int si, int ei, vector<string> contribution){
        //Base Case
        if(si > ei){
            res.push_back(contribution);
            return;
        }
            
        
        //Recursive Step
        for(int i=si ; i<=ei ; i++){
            string prefix = s.substr(si,i-si+1);
            if(!isPalindrome(prefix))
                continue;
            contribution.push_back(prefix);
            helper(s, i+1, ei, contribution);
            contribution.pop_back();
        }
    }
    vector<vector<string>> partition(string s) {
        //vector<string> contribution;
        helper(s, 0, s.size()-1, {});
        return res;
        
    }
};