class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        //If the array is already sorted the solution is the input array.
        // If not, move form right side of array toward left side until the point where the left element is larger than         right element.
        // At this point the left element (j) is one of the elements that should be swapped.
        // But to swap with what element?
        // We need to swap candid with the largest value on its right side that is less than j
        //in case of having repeated digits we prefer to swap it with the left most one to reach a larger number.
        
        
        int n = arr.size(), i;
        //this will give increase point
        //more importantly it will give one of the element to be swapped
        for(i=n-2 ; i>=0&&arr[i]<=arr[i+1] ; i--);
        if(i == -1) {
            return arr;
        }
        int j = i;
        //number to be swapped with
        int max_num = INT_MIN;
        int max_pos;
        for(i=j+1 ; i<n ; i++) {
            if(arr[i] < arr[j] && arr[i] > max_num) {
                max_num = arr[i];
                max_pos = i;
            }
        }
        swap(arr[j], arr[max_pos]);
        return arr;
    }
};