class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        sort(points.begin(), points.end(), [=](vector<int> a, vector<int> b)
             {
                 int dist1 = (a[0]*a[0])+(a[1]*a[1]);
                 int dist2 = (b[0]*b[0])+(b[1]*b[1]);
                 
                 return dist1<dist2;
             });
        
        while(points.size() != k)
            points.pop_back();
        
        return points;
    }
};