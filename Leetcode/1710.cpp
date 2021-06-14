class Solution {
public:
    static bool cmp(const vector<int> &a, const vector<int> &b)
    {
        return a[1] > b[1];
    }
    
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int len = boxTypes.size();
        int ret = 0;
        sort(boxTypes.begin(), boxTypes.end(), cmp);
        
        for(int i=0, j=0; i<len && j<truckSize; ++i)
        {
            int c = min(truckSize-j, boxTypes[i][0]);
            ret += c * boxTypes[i][1];
            j += c;
        }
        
        return ret;
    }
};