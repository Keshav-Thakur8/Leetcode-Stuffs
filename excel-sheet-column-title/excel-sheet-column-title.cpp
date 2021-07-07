class Solution {
public:
    string convertToTitle(int columnNumber) {
        string res;
        while(columnNumber > 0){
            char ch = (columnNumber-1)%26+'A';
            res.push_back(ch);
            columnNumber = (columnNumber-1)/26;
        }
        reverse(res.begin(), res.end());
        return res;
        
    }
};