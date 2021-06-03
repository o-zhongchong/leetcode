class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        horizontalCuts.push_back(0);
        horizontalCuts.push_back(h);
        verticalCuts.push_back(0);
        verticalCuts.push_back(w);
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        int len1 = horizontalCuts.size();
        int len2 = verticalCuts.size();
        int M = 1e9 + 7;
        long long d1, d2;
        d1 = d2 = 0;
        
        for(int i=1; i<len1; ++i)
        {
            d1 = max(d1, (long long)(horizontalCuts[i] - horizontalCuts[i-1]));
        }
        
        for(int i=1; i<len2; ++i)
        {
            d2 = max(d2, (long long)(verticalCuts[i] - verticalCuts[i-1]));
        }
        
        return (int)(((d1 % M) * (d2 % M)) % M);
    }
};