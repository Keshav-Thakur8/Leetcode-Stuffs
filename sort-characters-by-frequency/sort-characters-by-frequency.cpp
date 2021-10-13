// vector<int> freq(256,0);
// bool compare(char a, char b) {
//     // < operator --> ascending order
//     // > operator --> descending order
//     if(freq[a] == freq[b]) {
//         return a<b;
//     }
//     return freq[a]>freq[b];
// }

class Solution {
public:
    string frequencySort(string s) {
        vector<int> freq(256,0);
        for(char ch : s) {
            freq[ch]++;
        }
        // sort(s.begin(), s.end(), compare);
        sort(s.begin(), s.end(), [=](char a, char b) {
            if(freq[a] == freq[b]) {
                return a<b;
            }
            return freq[a]>freq[b];
        });
        
        return s;
    }
};