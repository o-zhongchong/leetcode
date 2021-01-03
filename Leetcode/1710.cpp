class Solution {
public:
    static bool comp(const vector<int>& a, const vector<int>& b)
    {
        return a[1] > b[1];
    }
    
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), comp);
        int sum = 0;
        int len = boxTypes.size();
        
        for(int i=0; i<len; ++i)
        {
            int cnt = min(truckSize, boxTypes[i][0]);
            truckSize -= cnt;
            sum += cnt * boxTypes[i][1];
        }
        
        return sum;
    }
};