class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        //key is box number, value is the count of each box
        unordered_map<int,int> counts;
        
        for(int i=lowLimit; i<=highLimit; ++i)
        {
            //get the sum of digits of the ball's number
            int digit_sum = 0;
            int n = i;
            
            while(n)
            {
                digit_sum += n%10;
                n /= 10;
            }
            
            //put each ball in the box
            if(counts.find(digit_sum) != counts.end())
            {
                ++counts[digit_sum];
            }
            else
            {
                counts[digit_sum] = 1;
            }
        }
        
        //the number of balls in the box with the most balls
        int ret = 0;
        
        for(auto &c : counts)
        {
            ret = max(ret, c.second);
        }
        
        return ret;
    }
};