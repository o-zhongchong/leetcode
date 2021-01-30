class Solution {
public:
    int minimumBoxes(int n) {
        vector<int> bottom(1, 0), total(1, 0);
        
        for(int i = 1; total[i-1] <= n; ++i)
        {
            bottom.push_back((1 + i) * i / 2);
            total.push_back(total[i-1] + bottom[i]);
        }
        
        int h = total.size() - 2;
        int r = n - total[h];
        int L = 0, R = h + 1;
        
        while(L < R)
        {
            int M = L + (R - L) / 2;
            
            if((1 + M) * M / 2 < r)
            {
                L = M + 1;
            }
            else
            {
                R = M;
            }
        }
        
        return bottom[h] + L;
    }
};