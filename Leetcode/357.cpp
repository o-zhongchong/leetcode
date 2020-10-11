class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        vector<int> s = {1, 9, 9*9, 9*9*8,
                         9*9*8*7, 9*9*8*7*6,
                        9*9*8*7*6*5,9*9*8*7*6*5*4,
                        9*9*8*7*6*5*4*3};
        
        if(n < 0 || n > 8)
        {
            return 0;
        }
        
        int sum = 0;
        
        for(int i=0; i<=n; ++i)
        {
            sum += s[i];
        }
        
        return sum;
    }
};