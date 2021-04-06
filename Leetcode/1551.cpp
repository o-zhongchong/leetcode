class Solution {
public:
    int minOperations(int n) {
        if(n <= 1)
        {
            return 0;
        }
        
        return n & 1 ? (n-1)*(n+1)/4 : n*n/4;
    }
};