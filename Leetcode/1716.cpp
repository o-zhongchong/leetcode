class Solution {
public:
    int totalMoney(int n) {
        int sum = 0;
        int week = 1;
        
        for(int i=0; i<n; ++i)
        {
            week = 1 + i / 7;
            sum += week + i % 7;
        }
        
        return sum;
    }
};