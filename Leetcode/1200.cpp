class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> ret;
        int len = arr.size();
        if(len < 2)
            return ret;
        
        sort(arr.begin(),arr.end());
        int minAbs = arr[1] - arr[0];
        
        for(int i=2; i<len; ++i)
        {
            int res = abs(arr[i]-arr[i-1]);
            if(  res < minAbs)
                minAbs = res;
        }
        
        for(int i=1; i<len; ++i)
        {
            int res = abs(arr[i]-arr[i-1]);;
            if(res == minAbs)
            {
                vector<int> pair = {arr[i-1],arr[i]};
                ret.push_back(pair);
            }
        }
        
        return ret;
    }
};