class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int i;
        for(i=0;i<bits.size();i++)
        {
            if(i==bits.size()-1)
                return true;
            if(bits[i]==1)
                i++;
        }
        return false;
        
    }
};