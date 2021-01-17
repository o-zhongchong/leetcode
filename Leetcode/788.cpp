class Solution {
public:
    int rotatedDigits(int N) {
        int valid[10] = {0,0,1,-1,-1,1,1,-1,0,1};
        int ret = 0;
        
        for(int i=1; i<=N; ++i)
        {
            int n = i;
            bool is_good =false;
            
            while(n)
            {
                if(valid[n%10] == -1)
                {
                    is_good = false;
                    break;
                }
                else if(valid[n%10] == 1)
                {
                    is_good = true;
                }
                
                n /= 10;
            }
            
            if(is_good)
            {
                ++ret;
            }
        }
        
        return ret;
    }
};