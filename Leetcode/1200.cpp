class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int len = arr.size();
        vector<vector<int>> ret;
        int d = arr[1] - arr[0];
        for(int i=2; i<len; ++i) {
            d = min(d, arr[i] - arr[i-1]);
        }
        for(int i=1; i<len; ++i) {
            if(arr[i] - arr[i-1] == d) {
                vector<int> t = {arr[i-1],arr[i]};
                ret.push_back(t);
            }
        }
        return ret;
    }
};