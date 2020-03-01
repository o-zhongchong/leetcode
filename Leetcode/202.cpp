class Solution {
public:
    bool isHappy(int n) {
        if(4 == n)
            return false;
        
        int sum = 0;
        while(n)
        {
            sum = sum + (n%10)*(n%10);
            n = n/10;
        }
        if(1==sum)
            return true;
        else
            return isHappy(sum);
    }
};